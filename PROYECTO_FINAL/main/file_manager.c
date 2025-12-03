#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "file_manager.h"

/* ---------------------------------------- */
/*  LECTURA DE ARCHIVO                      */
/* ---------------------------------------- */
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

/* ---------------------------------------- */
/*  ESCRITURA DE ARCHIVO                    */
/* ---------------------------------------- */
int write_file(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");
    if (!file) return 0;

    fwrite(data, sizeof(char), strlen(data), file);
    fclose(file);
    return 1;
}

/* ---------------------------------------- */
/*  CAPTURA DE IMPRESIÓN (HISTORIAL)        */
/* ---------------------------------------- */

static FILE *hist_file = NULL;
static int capturing = 0;

void start_history_capture() {
    if (capturing) return; /* ya activo */
    hist_file = fopen("historial.txt", "a");
    if (!hist_file) {
        fprintf(stderr, "Error al abrir historial.txt para escritura\n");
        hist_file = NULL;
        capturing = 0;
        return;
    }
    capturing = 1;
}

void stop_history_capture() {
    if (hist_file) {
        fflush(hist_file);
        fclose(hist_file);
        hist_file = NULL;
    }
    capturing = 0;
}

int history_printf(const char *fmt, ...) {
    int r = 0;
    va_list args;

    va_start(args, fmt);
    r = vprintf(fmt, args);
    va_end(args);

    if (capturing && hist_file) {
        va_start(args, fmt);
        vfprintf(hist_file, fmt, args);
        va_end(args);
        fflush(hist_file);
    }

    return r;
}


