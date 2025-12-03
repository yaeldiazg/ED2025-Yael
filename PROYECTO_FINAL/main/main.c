#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "stack.h"
#include "utils.h"
#include "infix_to_postfix.h"
#include "infix_to_prefix.h"
#include "postfix_to_infix.h"
#include "postfix_to_prefix.h"
#include "prefix_to_infix.h"
#include "prefix_to_postfix.h"
#include "file_manager.h"

/* Función para mostrar ayuda */
void print_help() {
    printf("Uso: calc [opcion]\n");
    printf("Opciones:\n");
    printf("  -h        Mostrar este menu de ayuda\n");
    printf("  -i2p      Infix -> Postfix\n");
    printf("  -i2x      Infix -> Prefix\n");
    printf("  -p2i      Postfix -> Infix\n");
    printf("  -p2x      Postfix -> Prefix\n");
    printf("  -x2i      Prefix -> Infix\n");
    printf("  -x2p      Prefix -> Postfix\n");
}

/* Validación de paréntesis */
int validate_parentheses(List *tokens) {
    Stack s;
    stack_init(&s);

    for (ListNode *elmt = list_head(tokens); elmt != NULL; elmt = list_next(elmt)) {
        char *t = (char*) list_data(elmt);

        if (t[0] == '(') {
            stack_push(&s, "(");
        }
        else if (t[0] == ')') {
            char *top = stack_pop(&s);

            if (!top) {
                stack_destroy(&s);
                return 0;
            }

            free(top);
        }
    }

    int balanced = (list_size(&s.list) == 0);

    while (list_size(&s.list) > 0) {
        char *d = stack_pop(&s);
        if (d) free(d);
    }

    stack_destroy(&s);
    return balanced;
}


int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_help();
        return 0;
    }

    if (strcmp(argv[1], "-h") == 0) {
        print_help();
        return 0;
    }

    char expr[1024];
    printf("Ingrese expresion: ");
    if (!fgets(expr, sizeof(expr), stdin)) {
        fprintf(stderr, "Error leyendo la expresion\n");
        return 1;
    }
    expr[strcspn(expr, "\n")] = 0; // quitar salto de linea

    List *tokens = tokenize(expr);
    if (!tokens) {
        fprintf(stderr, "Error al tokenizar la expresion\n");
        return 1;
    }

    if (!validate_parentheses(tokens)) {
        fprintf(stderr, "Error: parentesis desbalanceados\n");
        list_destroy(tokens);
        free(tokens);
        return 1;
    }

    char *resultado = NULL;
    char tipo[64];

    if (strcmp(argv[1], "-i2p") == 0) {
        strcpy(tipo, "Infix -> Postfix");
        resultado = infix_to_postfix(tokens);
    } else if (strcmp(argv[1], "-i2x") == 0) {
        strcpy(tipo, "Infix -> Prefix");
        resultado = infix_to_prefix(tokens);
    } else if (strcmp(argv[1], "-p2i") == 0) {
        strcpy(tipo, "Postfix -> Infix");
        resultado = postfix_to_infix(tokens);
    } else if (strcmp(argv[1], "-p2x") == 0) {
        strcpy(tipo, "Postfix -> Prefix");
        resultado = postfix_to_prefix(tokens);
    } else if (strcmp(argv[1], "-x2i") == 0) {
        strcpy(tipo, "Prefix -> Infix");
        resultado = prefix_to_infix(tokens);
    } else if (strcmp(argv[1], "-x2p") == 0) {
        strcpy(tipo, "Prefix -> Postfix");
        resultado = prefix_to_postfix(tokens);
    } else {
        fprintf(stderr, "Opcion desconocida: %s\n", argv[1]);
        print_help();
    }

    if (resultado) {
        printf("Resultado (%s): %s\n", tipo, resultado);

        free(resultado);
    } else {
        fprintf(stderr, "Error: conversion invalida\n");
    }

    list_destroy(tokens);
    free(tokens);

    return 0;
}


