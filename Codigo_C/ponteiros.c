#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void my_function(int * num);

int main(){
    setlocale(LC_ALL, "Portuguese");

    int num = 5;
    printf("%d\n", num);
    my_function(&num);
    printf("%d\n", num);
    
    return 0;
}

void my_function(int* num){
    *num *= 3;
}