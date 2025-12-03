#ifndef PARSER_H
#define PARSER_H

#include "list.h"

// Convierte una expresión en cadena a lista de tokens
List *tokenize(const char *expr);

#endif
