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
Considere el  siguiente arreglo matricial:

```markdown
| Nombre   | Edad | Calificación |
|----------|------|--------------|
| Alberto  | 22   | 9            |
| Fernando | 19   | 4            |
| ...      | ...  | ...          |
| Brenda   | 34   | 7            |
```

Realice un programa que acepte una lista de *n* alumnos, el arreglo deberá ser de *n*x3, la primera columna deberá tener un espacio de 25 caracteres, la segunda y tercera deberá aceptar números enteros.

- El programa debe solicitar al usuario si desea o no agregar más alumnos.
- El programa después de capturar los datos, deberá devolver el promedio de edad y de calificación grupal.
- El programa deberá imprimir los nombres de los alumnos en sentido inverso al que fueron 
ingresados o se encuentran almacenados.
- Puede ser del tipo char todo el arreglo, solo recuerde hacer el "casteo" para los elementos numéricos.
