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

void print_help() {
    history_printf("Uso: calc [opcion]\n");
    history_printf("Opciones:\n");
    history_printf("  -h        Mostrar este menu de ayuda\n");
    history_printf("  -i2p      Infix -> Postfix\n");
    history_printf("  -i2x      Infix -> Prefix\n");
    history_printf("  -p2i      Postfix -> Infix\n");
    history_printf("  -p2x      Postfix -> Prefix\n");
    history_printf("  -x2i      Prefix -> Infix\n");
    history_printf("  -x2p      Prefix -> Postfix\n");
}

int main(int argc, char *argv[]) {
    start_history_capture();

    if (argc < 2) {
        print_help();
        stop_history_capture();
        return 0;
    }

    if (strcmp(argv[1], "-h") == 0) {
        print_help();
        stop_history_capture();
        return 0;
    }

    char expr[1024];
    history_printf("Ingrese expresion: ");
    if (!fgets(expr, sizeof(expr), stdin)) {
        fprintf(stderr, "Error leyendo la expresion\n");
        stop_history_capture();
        return 1;
    }
    expr[strcspn(expr, "\n")] = 0; // quitar salto de linea

    List *tokens = tokenize(expr);
    if (!tokens) {
        fprintf(stderr, "Error al tokenizar la expresion\n");
        stop_history_capture();
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
        history_printf("Resultado (%s): %s\n", tipo, resultado);
        free(resultado);
    } else {
        fprintf(stderr, "Error: conversion invalida\n");
    }

    list_destroy(tokens);
    free(tokens);

    stop_history_capture();
    return 0;
}


