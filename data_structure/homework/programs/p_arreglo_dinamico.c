#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CONVIERTE LETRA A NÚMERO DEPENDIENDO SU POSICIÓN EN EL ABECEDARIO Y RETORNA 0 SI NO ES UNA LETRA MAYUSCULA 
int letra_a_numero(char letra) {
    if (letra >= 'A' && letra <= 'Z') {
        return letra - 'A' + 1; 
    }
    return 0; 
}

int main(int argc, char *argv[]){

    char *palabra = argv[1];
    int len = strlen(palabra);

    int **jarray = (int **) malloc(len * sizeof(int *));
    int i, j;

    for (i = 0; i < len; i++) {
        int cant = letra_a_numero(palabra[i]);
        
        if (cant == 0) { 
            jarray[i] = NULL;
            printf("NULL\n", palabra[i]);
        } else {
            jarray[i] = (int *) malloc(cant * sizeof(int));
            for (j = 0; j < cant; j++) {
                jarray[i][j] = palabra[i]; 
                printf("%c ", jarray[i][j]);
            }
            printf("\n");
        }
    }
    
    for (i = 0; i < len; i++) {
        free(jarray[i]);
    }
    free(jarray);

    return 0;
}
