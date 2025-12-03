#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include "stack.h"
#include "list.h"
#include "utils.h"
#include "prefix_to_infix.h"
#include "postfix_to_infix.h"

char *prefix_to_infix(List *tokens) {
    List reversed;
    list_init(&reversed, free);

    ListNode *elmt = list_head(tokens);
    while (elmt != NULL) {
        char *copy = my_strdup(list_data(elmt));
        list_ins_next(&reversed, NULL, copy);
        printf("Invertido token: %s\n", copy);
        elmt = list_next(elmt);
    }

    char *result = postfix_to_infix(&reversed);
    list_destroy(&reversed);
    return result;
}
