#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int factRecursion(int n){
	if(n < 0){
		return 0;
	} else if(n == 0){
		return 1;
	} else if(n == 1){
		return n;
	}
	else{
		return n*factRecursion(n-1);
	}
}

int main(int argc, char *argv[]){
	int i;
	char *num = argv[1];
	
	fprintf(stdout, "arg[1] = %s \n", argv[1]);
	for(i = 0; i < strlen(argv[1]); i++){
		fprintf(stdout, "num[%d] = %c \n", i, num[i]);
	}
	
	int n = atoi(num);
	int f = factRecursion(n);
	
	printf("Factorial de %d = %d",n,f);
	return 0;
}