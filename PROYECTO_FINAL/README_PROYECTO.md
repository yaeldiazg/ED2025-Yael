# Calculadora de Expresiones Matemáticas

Este proyecto es una calculadora en **C** que permite convertir y evaluar expresiones en **infix**, **postfix** y **prefix**. Está segmentado en módulos, utilizando estructuras de datos como **pila (stack)** y **listas** para el manejo de los tokens y la evaluación paso a paso.

## Integrantes del proyecto

- **Yael Eduardo Díaz Gómez** [Número de cuenta: 322505188]  
- **Hernández Netzahuatl Diego** [Número de cuenta: 425094006]  

## Funcionalidades

- Conversión de expresiones:
  - Infix → Postfix
  - Infix → Prefix
  - Postfix → Infix
  - Postfix → Prefix
  - Prefix → Infix
  - Prefix → Postfix
- Evaluación paso a paso mostrando:
  - Estado de la pila
  - Resultado parcial de la operación
- Manejo de números negativos
- Validación de errores:
  - Expresiones mal formadas
  - Paréntesis desbalanceados
- Guardado de resultados en archivos (historial)
- Menú de ayuda con la opción `-h`

## Archivos del proyecto

- `main.c` → Interfaz principal del programa
- `stack.h / stack.c` → Implementación de la pila
- `list.h / list.c` → Implementación de listas simples
- `file_manager.h / file_manager.c` → Lectura y escritura de archivos
- `parser.h / parser.c` → Tokenización de expresiones
- `infix_to_postfix.h / infix_to_postfix.c`
- `infix_to_prefix.h / infix_to_prefix.c`
- `postfix_to_infix.h / postfix_to_infix.c`
- `postfix_to_prefix.h / postfix_to_prefix.c`
- `prefix_to_infix.h / prefix_to_infix.c`
- `prefix_to_postfix.h / prefix_to_postfix.c`
- `utils.h / utils.c` → Funciones auxiliares

## Uso

Compilar el proyecto:

```bash
gcc -std=c99 -Wall -Wextra -Iinclude main/*.c -o calc.exe -D_POSIX_C_SOURCE=200809L

Ejecutar el programa:
./calc.exe -i2p

Para mostrar la ayuda:
./calc.exe -h

Historial de resultados:

Todos los resultados se guardan en historial.txt, incluyendo la expresión, tipo de conversión y resultado.