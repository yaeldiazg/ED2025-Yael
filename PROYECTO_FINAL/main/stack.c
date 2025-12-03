#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "utils.h"


void stack_init(Stack *s) {
    list_init(&s->list, free);
}

int stack_push(Stack *s, const char *data) {
    char *copy = my_strdup(data);
    if (!copy) return -1;

    // Insertar después del tail ? agrega al final
    return list_ins_next(&s->list, list_tail(&s->list), copy);
}

char *stack_pop(Stack *s) {
    if (list_size(&s->list) == 0)
        return NULL;

    ListNode *prev = NULL;
    ListNode *curr = list_head(&s->list);

    // Avanzar hasta el último nodo
    while (list_next(curr) != NULL) {
        prev = curr;
        curr = list_next(curr);
    }

    char *data = list_data(curr);

    // Remover curr, usando prev
    list_rem_next(&s->list, prev, (void**)&data);

    return data;
}

char *stack_peek(Stack *s) {
    if (list_size(&s->list) == 0)
        return NULL;

    ListNode *curr = list_head(&s->list);

    // Avanzar hasta el último nodo
    while (list_next(curr) != NULL)
        curr = list_next(curr);

    return list_data(curr);
}

void stack_destroy(Stack *s) {
    list_destroy(&s->list);
}


