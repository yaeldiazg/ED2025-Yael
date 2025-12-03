#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <stdio.h>
#include <stdlib.h>

int read_file(const char *filename, char **buffer);
int write_file(const char *filename, const char *data);

#endif
