#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void diezPares(int i, int n){
	int par = 2;
	int numPares[10] = {};
	for(i=0; i<10; i++){
		numPares[i] = par;
		par += 2;
	}
	printf("Pares en orden inverso \n");
	for(i=9; i>=0; i--){
		printf("%d ",numPares[i]);
	}
	numPares[n] = -1;
	printf("\nIndice modificado: \n");
	for(i=0; i<10; i++){
		printf("%d ",numPares[i]);
	}
}

int main(int argc, char *argv[]){
	int i;
	char *num = argv[1];
	
	fprintf(stdout, "arg[1] = %s \n", argv[1]);
	for(i=0; i<strlen(argv[1]); i++){
		fprintf(stdout, "num[%d] = %c \n", i, num[i]);
	}
	
	int n = num[strlen(num)-1] - '0';
	diezPares(i,n);
}
