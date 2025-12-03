#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <ctype.h>
#include "infix_to_postfix.h"
#include "stack.h"

int precedence(char op) {
    switch(op){
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
    }
    return 0;
}

char* infix_to_postfix(List *tokens) {
    Stack s;
    stack_init(&s);

    char *result = (char*)calloc(1024, 1);

    for (ListNode *elmt = list_head(tokens); elmt != NULL; elmt = list_next(elmt)) {
        char *t = (char*)list_data(elmt);
        printf("Token actual: %s\n", t);

        if (isdigit(t[0]) || (t[0]=='-' && isdigit(t[1]))) {
            strcat(result, t);
            strcat(result, " ");
            printf("Añadido a resultado: %s\n", result);
        } else if (t[0]=='(') {
            stack_push(&s, t);
            printf("Push '(' a pila\n");
        } else if (t[0]==')') {
            while (stack_peek(&s)[0] != '(') {
                char *op = stack_pop(&s);
                strcat(result, op);
                strcat(result, " ");
                printf("Pop de pila: %s -> resultado: %s\n", op, result);
                free(op);
            }
            // Sacamos el '(' de la pila
            char *op = stack_pop(&s);
            free(op);
            printf("Pop de '(' de pila\n");
        } else {
            while (stack_peek(&s) && precedence(stack_peek(&s)[0]) >= precedence(t[0])) {
                char *op = stack_pop(&s);
                strcat(result, op);
                strcat(result, " ");
                printf("Pop de pila por precedencia: %s -> resultado: %s\n", op, result);
                free(op);
            }
            stack_push(&s, t);
            printf("Push operador a pila: %s\n", t);
        }
    }

    // Vaciar la pila restante
    while (stack_peek(&s)) {
        char *op = stack_pop(&s);
        strcat(result, op);
        strcat(result, " ");
        printf("Pop final de pila: %s -> resultado: %s\n", op, result);
        free(op);
    }

    stack_destroy(&s);
    return result;
}
