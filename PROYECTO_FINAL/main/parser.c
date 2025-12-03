#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>  


#include "parser.h"

/*
    Convierte la cadena expr en una lista de tokens (List*).
    Cada token es un string (char*) que representa un número u operador.
*/
List* tokenize(const char *expr) {
    List *tokens = malloc(sizeof(List));
    list_init(tokens, free);

    int i = 0;
    int len = strlen(expr);

    char last_token[64] = "";  // Guardar el último token para detectar multiplicación implícita

    while (i < len) {
        if (expr[i] == ' ') {
            i++;
            continue;
        }

        /* Paréntesis */
        if (expr[i] == '(' || expr[i] == ')') {
            char current = expr[i];

            if (current == '(' && 
                (isdigit(last_token[0]) || last_token[0] == ')')) {

                char *mul = malloc(2);
                strcpy(mul, "*");
                list_ins_next(tokens, list_tail(tokens), mul);
            }

            char *tok = malloc(2);
            tok[0] = current;
            tok[1] = 0;
            list_ins_next(tokens, list_tail(tokens), tok);

            strcpy(last_token, tok);
            i++;
            continue;
        }

        /* Operadores */
        if (strchr("+-*/^", expr[i])) {
            char *tok = malloc(2);
            tok[0] = expr[i];
            tok[1] = 0;
            list_ins_next(tokens, list_tail(tokens), tok);

            strcpy(last_token, tok);
            i++;
            continue;
        }

        /* Números */
        if (isdigit(expr[i])) {
            int start = i;
            while (i < len && isdigit(expr[i])) {
                i++;
            }
            int size = i - start;
            char *tok = malloc(size + 1);
            strncpy(tok, &expr[start], size);
            tok[size] = 0;
            list_ins_next(tokens, list_tail(tokens), tok);

            strcpy(last_token, tok);
            continue;
        }

        printf("Token inválido: '%c'\n", expr[i]);
        list_destroy(tokens);
        free(tokens);
        return NULL;
    }

    return tokens;
}

