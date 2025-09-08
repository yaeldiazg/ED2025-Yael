## Arreglos bidimensionales
La declaración de un arreglo bidimensional en lenguaje C se realiza de la siguiente forma.

``` C
[data type] variable [dimension1][dimension2];
```

por ejemplo:
Inicialización y uso de un arreglo bidimensional dinámico
``` C
int rows = 2;  
int columns = 5;  
int **matrix = (int **) malloc(rows * sizeof(int *));  

for (int i = 0; i < rows; i++) {  
	matrix[i] = (int *) malloc(columns * sizeof(int));  
}

```

### Programa
Genere un arreglo dinámico variable bidimensional de acuerdo con la palabra y la letra del abecedario este será rellenado  de la siguiente forma.

El usuario ingresará una cadena, por ejemlo `COMPUTACION.` y esta será segmentada de la siguiente manera

```markdown
./ P2E_arreglo_variable.exe COMPUTACION.
| C | C | C | 
| O | O | O | O | O | O | O | O | O | O | O | O | O | O | O |
| M | M | M | M | M | M | M | M | M | M | M | M | M |
| P | P | P | P | P | P | P | P | P | P | P | P | P | P | P | P |
| U | U | U | U | U | U | U | U | U | U | U | U | U | U | U | U | U | U | U | U | U |
| T | T | T | T | T | T | T | T | T | T | T | T | T | T | T | T | T | T | T | T |	
| A |
| C | C | C |
| I | I | I | I | I | I | I | I | I |
| O | O | O | O | O | O | O | O | O | O | O | O | O | O | O |
| N | N | N | N | N | N | N | N | N | N | N | N |
NULL
```

- El programa deberá ejecutarse con la cadena, como se ve en el ejemplo previo
- El programa solo deberá aceptar letras mayúsculas, cualquier otra letra, dígito o caracter deberá ser marcado como null.
- Considere el programa __read_dynamic_strings.c__ que se encuentra en la carpeta de tips and tricks para la contrucción de este programa.

*nota*: en los ejemplos previos no se ha considerado el caso en que no sea posible asignar el espacio necesario de forma dinámica
``` C
if (ptr == NULL)
	return -1;
```

Se recomienda la lectura del libro: Understanding and Using C Pointers, capítulo 4 y 5.