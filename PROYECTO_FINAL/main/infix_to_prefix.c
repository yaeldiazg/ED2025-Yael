#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <ctype.h>
#include "infix_to_prefix.h"
#include "infix_to_postfix.h"
#include "stack.h"
#include "utils.h"
#include "list.h"
#include "parser.h"
#include "file_manager.h"

char* infix_to_prefix(List *tokens) {
    List reversed;
    list_init(&reversed, free);

    history_printf("Invirtiendo tokens para prefix\n");
    for (ListNode *elmt = list_tail(tokens); elmt != NULL; elmt = list_prev(tokens, elmt)) {
        char *copy = my_strdup((char*)list_data(elmt));
        history_printf("Token invertido: %s\n", copy);
        list_ins_next(&reversed, NULL, copy);
    }

    char *postfix = infix_to_postfix(&reversed);

    int len = strlen(postfix);
    char *prefix = (char*)malloc(len+1);
    for (int i=0; i<len; i++) prefix[i] = postfix[len-1-i];
    prefix[len] = '\0';

    free(postfix);
    list_destroy(&reversed);
    return prefix;
}
