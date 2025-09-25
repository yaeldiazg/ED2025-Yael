#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    char *msj;
    int i=0;

    msj = (char*) malloc(sizeof(char));

    if (msj != NULL) {
        while ((msj[i] = getchar()) != '\t') {
            msj = (char*) realloc (msj, sizeof(char) * strlen(msj));
            
            if(msj!=NULL) {
                i++;        
            } else {
                printf("%s\n", "Something is wrong");        
                exit(0);
            }
        }
        printf("%s\n", msj);
        free(msj);

    } else {
        printf("%s\n", "Something is wrong");        
    }    

    return 0;
}

