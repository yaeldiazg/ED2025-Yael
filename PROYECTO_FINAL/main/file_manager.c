#include <string.h>  

#include "file_manager.h"

int read_file(const char *filename, char **buffer) {
    FILE *file = fopen(filename, "r");
    if (!file) return 0;

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    *buffer = malloc(size + 1);
    if (!*buffer) {
        fclose(file);
        return 0;
    }

    fread(*buffer, 1, size, file);
    (*buffer)[size] = '\0';
    fclose(file);
    return 1;
}

int write_file(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");
    if (!file) return 0;

    fwrite(data, sizeof(char), strlen(data), file);
    fclose(file);
    return 1;
}
