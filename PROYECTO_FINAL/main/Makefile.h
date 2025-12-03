# Compilador
CC = gcc

# Flags de compilación
CFLAGS = -Iinclude -Wall -Wextra -g

# Carpeta de código fuente
SRC = main

# Archivos fuente
SRCS = $(SRC)/main.c \
       $(SRC)/stack.c \
       $(SRC)/infix_to_postfix.c \
       $(SRC)/infix_to_prefix.c \
       $(SRC)/postfix_to_infix.c \
       $(SRC)/postfix_to_prefix.c \
       $(SRC)/prefix_to_infix.c \
       $(SRC)/prefix_to_postfix.c

# Nombre del ejecutable
TARGET = calc.exe

# Regla por defecto
all: $(TARGET)

# Compilación
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Limpiar objetos y ejecutable
clean:
	del $(TARGET) 2>nul
