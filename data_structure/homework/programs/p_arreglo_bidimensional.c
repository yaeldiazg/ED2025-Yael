#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100 

int main(){
	int n = 0;
	int i,j;
    char ***alumnos = NULL;
    char opcion;
    
	do{
		alumnos = (char ***) realloc(alumnos, (n + 1) * sizeof(char **));
        alumnos[n] = (char **) malloc(3 * sizeof(char *));
        alumnos[n][0] = (char *) malloc(25 * sizeof(char));
        for (j = 1; j < 3; j++) {
            alumnos[n][j] = (char *) malloc(3 * sizeof(char));
        }
        
		printf("\nAlumno %d\n", n + 1);

        printf("Nombre: ");
        scanf(" %24[^\n]", alumnos[n][0]);

        printf("Edad: ");
        scanf("%9s", alumnos[n][1]); 

        printf("Calificacion: ");
        scanf("%9s", alumnos[n][2]); 

        n++;

        printf("Desea agregar otro alumno? (s/n): ");
        scanf(" %c", &opcion);
        
	} while ((opcion == 's' || opcion == 'S') && n < MAX);
	
	int sumEdad = 0, sumCali = 0;
	for(i = 0; i < n; i++){
		sumEdad += atoi(alumnos[i][1]);
		sumCali += atoi(alumnos[i][2]);
	}
	
	float promEdad = (float)sumEdad / n;
	float promCali = (float)sumCali / n;
	
	printf("\n--- Resultados ---\n");
    printf("Promedio de edad: %.2f\n", promEdad);
    printf("Promedio de calificacion: %.2f\n", promCali);
    
    printf("\n--- Nombres en orden inverso ---\n");
    for (i = n-1; i >= 0; i--) {
        printf("%s\n", alumnos[i][0]);
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < 3; j++) {
            free(alumnos[i][j]);
        }
        free(alumnos[i]);
    }
    free(alumnos);
    
    return 0;
}
