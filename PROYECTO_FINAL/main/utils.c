#include <stdlib.h>
#include <string.h>
#include "utils.h"

char *my_strdup(const char *s) {
    if (!s) return NULL;
    char *copy = malloc(strlen(s) + 1);
    if (!copy) return NULL;
    strcpy(copy, s);
    return copy;
}
