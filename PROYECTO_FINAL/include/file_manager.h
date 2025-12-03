#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/* Lectura */
int read_file(const char *filename, char **buffer);

/* Escritura */
int write_file(const char *filename, const char *data);

/* Captura todo lo que se imprime */
void start_history_capture();
void stop_history_capture();

int history_printf(const char *fmt, ...);

#endif
