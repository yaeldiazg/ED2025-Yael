#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>  


#include "parser.h"

/*
    Convierte la cadena expr en una lista de tokens (List*).
    Cada token es un string (char*) que representa un número u operador.
*/
List *tokenize(const char *expr) {
    List *tokens = (List *)malloc(sizeof(List));
    if (!tokens) return NULL;
    list_init(tokens, free);

    int i = 0;
    while (expr[i] != '\0') {
        if (isspace(expr[i])) {
            i++;
            continue;
        }

        if (isdigit(expr[i]) || (expr[i] == '-' && isdigit(expr[i + 1]))) {
            int start = i;
            i++;
            while (isdigit(expr[i])) i++;
            int len = i - start;
            char *num = (char *)malloc(len + 1);
            if (!num) {
                list_destroy(tokens);
                free(tokens);
                return NULL;
            }
            strncpy(num, expr + start, len);
            num[len] = '\0';
            list_ins_next(tokens, NULL, num);
        } else {
            // operador
            char *op = (char *)malloc(2);
            if (!op) {
                list_destroy(tokens);
                free(tokens);
                return NULL;
            }
            op[0] = expr[i];
            op[1] = '\0';
            list_ins_next(tokens, NULL, op);
            i++;
        }
    }

    return tokens;
}
