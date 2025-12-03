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

void save_history(const char *input_exp, const char *converted_exp, const char *result_exp) {
    FILE *f = fopen("historial.txt", "a");
    if (!f) {
        printf("Error al abrir historial.txt\n");
        return;
    }

    fprintf(f, "====================================\n");
    fprintf(f, "OPERACIÓN ORIGINAL:\n%s\n\n", input_exp);
    fprintf(f, "CONVERSIÓN REALIZADA:\n%s\n\n", converted_exp);
    fprintf(f, "RESULTADO FINAL:\n%s\n", result_exp);
    fprintf(f, "====================================\n\n");

    fclose(f);
}
