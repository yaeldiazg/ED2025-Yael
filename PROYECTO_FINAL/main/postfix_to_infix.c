#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <ctype.h>
#include "stack.h"
#include "list.h"
#include "utils.h"
#include "postfix_to_infix.h"
#include "file_manager.h"

char *postfix_to_infix(List *tokens) {
    Stack s;
    stack_init(&s);

    ListNode *elmt = list_head(tokens);
    while (elmt != NULL) {
        char *t = (char *)list_data(elmt);

        if (isdigit(t[0]) || (t[0] == '-' && isdigit(t[1]))) {
            stack_push(&s, t);
            history_printf("Push número a pila: %s\n", t);
        } else {
            char *b = stack_pop(&s);
            char *a = stack_pop(&s);
            history_printf("Pop de pila: a=%s, b=%s, operador=%s\n", a, b, t);

            char buffer[256];
            snprintf(buffer, sizeof(buffer), "(%s%s%s)", a, t, b);

            stack_push(&s, my_strdup(buffer));
            history_printf("Push resultado parcial a pila: %s\n", buffer);
        }
        elmt = list_next(elmt);
    }

    char *result = stack_pop(&s);
    stack_destroy(&s);
    return result;
}
