# Programa: P2 - Descomposición del número de cuenta
Realice un programa en C que genere una lista de los primeros 10 números pares, deberá imprimirlos en orden inverso.

Ejemplo de la salida del programa.
```markdown
| 20 | 18 | 16 | 14 | 12 | 10 | 8 | 6 | 4 | 2 |
```

Posteriormente deberá modificar el valor almacenado en el índice correspondiente al último dígito de su número cuenta por -1.
```markdown
Indice | 0 | 1 | 2 | 3 | 4  | 5	 | 6  | 7  | 8  | 9  |
Valor  | 2 | 4 | 6 | 8 | 10 | 12 | 14 | 16 | 18 | 20 |
```
Por ejemplo, suponga que su número de cuenta es el siguiente 410092686, el último número es 6, por lo que deberá buscar el índice donde se encuentra el número 6 y sustituir el valor almacenado por -1.
```markdown
Indice | 0 | 1 | 2 | 3 | 4  | 5	 | __6__  | 7  | 8  | 9  |
Valor  | 2 | 4 | 6 | 8 | 10 | 12 | __-1__ | 16 | 18 | 20 |
```
El programa deberá llamarse __p_arreglo_cuenta.c__ y deberá encontrarse en la carpeta _/homework/programs/_ 

Por ejemplo.
```
data_structure/
├── code
│	├── include
│	├── main
│	└── source
└── homework
    ├── activities
    └── programs
        └── p_arreglo_cuenta.c
```