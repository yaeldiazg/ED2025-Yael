#include <stdio.h>
#include <stdlib.h>
#include <string.h>  

#include "stack.h"
#include "utils.h"

void stack_init(Stack *s) {
    list_init(&s->list, free);
}

void stack_destroy(Stack *s) {
    list_destroy(&s->list);
}

int stack_push(Stack *s, const char *data) {
    char *copy = my_strdup(data);
    if (!copy) return -1;
    int ret = list_ins_next(&s->list, NULL, copy);
    if (ret == 0) {
        printf("[Stack PUSH] '%s' -> Pila actual: ", copy);
        ListNode *node = list_head(&s->list);
        while (node) {
            printf("%s ", (char*)list_data(node));
            node = list_next(node);
        }
        printf("\n");
    }
    return ret;
}


char *stack_pop(Stack *s) {
    if (list_size(&s->list) == 0) return NULL;

    ListNode *tail = list_tail(&s->list);
    char *data = (char *)list_data(tail);
    list_rem_next(&s->list, NULL, (void **)&data);

    printf("[Stack POP] '%s' -> Pila actual: ", data);
    ListNode *node = list_head(&s->list);
    while (node) {
        printf("%s ", (char*)list_data(node));
        node = list_next(node);
    }
    printf("\n");

    return data;
}

char *stack_peek(Stack *s) {
    if (list_size(&s->list) == 0) return NULL;
    char *data = (char *)list_data(list_tail(&s->list));
    printf("[Stack PEEK] '%s'\n", data);
    return data;
}
