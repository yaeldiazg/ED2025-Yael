#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include "parser.h"
#include "stack.h"
#include "list.h"
#include "postfix_to_prefix.h"
#include "postfix_to_infix.h"
#include "infix_to_prefix.h"

char *postfix_to_prefix(List *tokens) {
    char *infix = postfix_to_infix(tokens);
    printf("Convertido postfix -> infix: %s\n", infix);

    List *tokenized = tokenize(infix);
    char *prefix = infix_to_prefix(tokenized);
    printf("Convertido infix -> prefix: %s\n", prefix);

    free(infix);
    return prefix;
}
