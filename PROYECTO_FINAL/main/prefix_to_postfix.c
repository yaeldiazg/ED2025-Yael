#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include "stack.h"
#include "list.h"
#include "parser.h"
#include "prefix_to_postfix.h"
#include "prefix_to_infix.h"
#include "infix_to_postfix.h"

char *prefix_to_postfix(List *tokens) {
    char *infix = prefix_to_infix(tokens);
    printf("Convertido prefix -> infix: %s\n", infix);

    List *tokenized = tokenize(infix);
    char *result = infix_to_postfix(tokenized);
    printf("Convertido infix -> postfix: %s\n", result);

    free(infix);
    return result;
}
