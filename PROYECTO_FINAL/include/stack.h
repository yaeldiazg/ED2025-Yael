#ifndef STACK_H
#define STACK_H

#include "list.h"

typedef struct Stack_ {
    List list;
} Stack;

// Inicializa la pila
void stack_init(Stack *s);

// Destruye la pila
void stack_destroy(Stack *s);

// Agrega un elemento a la pila
int stack_push(Stack *s, const char *data);

// Remueve el elemento superior de la pila y lo retorna
char *stack_pop(Stack *s);

// Retorna el elemento superior sin removerlo
char *stack_peek(Stack *s);

#endif
