#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int n,m,i,j;
	printf("Dame el valor de n: ");
	scanf("%d", &n);
	printf("Dame el valor de m: ");
	scanf("%d", &m);
	
	int matriz[n][m];
	
	printf("\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			printf("Dame el valor para (%d,%d): ",i,j);
			scanf("%d", &matriz[i][j]);
		}
	}
	
	printf("\n");
	// RECORRIDO POR FILAS
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			printf("%d ",matriz[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	// RECORRIDO POR COLUMNAS
	for(i = m-1; i >= 0; i--){
		for(j = n-1; j >= 0; j--){
			printf("%d ",matriz[j][i]);
		}
		printf("\n");
	}
	
	printf("\n");
	// RECORRIDO DIAGONAL
	if(n <= m){
    	for(i = 0; i < n; i++){
        	printf("%d\n", matriz[i][i]);
    	}
	} else{
    	for(i = 0; i < m; i++){
        	printf("%d\n", matriz[i][i]);
    	}
	}
	
	return 0;
}
