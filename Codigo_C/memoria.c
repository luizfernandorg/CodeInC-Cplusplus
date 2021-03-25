#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");//useless in Windows, good to go in Linux though

    int * numeros = malloc(4 * sizeof(int));// Allocate memory for the vector of type int
    if(numeros == NULL){
        printf("Error, got an error while allocate space memory");
        return 1;
    }

    numeros = realloc(numeros, 4 * sizeof(int));// Give more memory to the vector
    if(numeros == NULL){
        printf("Error, got an error while allocate space memory");
        return 1;
    }

    free(numeros);//always clear the memory that is not more in use
    return 0;
}

