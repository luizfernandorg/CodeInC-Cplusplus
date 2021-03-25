#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define bool char
#define true 1
#define false 0
void Dec2Bin(int n){
    
    if(n<2)
        printf("%d",n);
    else {
        Dec2Bin(n/2);
        printf("%d", n%2);
    }
}
int main(int argc, char const *argv[])
{
    bool teste = 5 == 5;
    if(teste){
        printf("São iguais");
    } else {
        printf("São diferentes");
    }
    printf("\n");
    printf("Locale is %s\n\n", setlocale(LC_ALL, NULL));
    setlocale(LC_ALL, "pt_BR.utf-8");
    printf("Now locale is é ão â %s\n\n", setlocale(LC_ALL, NULL));

    printf("Main application for test proposal\n\n");
    system("pause");
    int decimal;
    int op;
    while(1){
        system("cls");
        printf("Informe o valor decimal para converter para binário: ");
        scanf("%d",&decimal);
        printf("O valor %d em binario é :", decimal );
        Dec2Bin(decimal);

        printf("\nDigite 1 para tentar outro decimal ou 0 para sair: ");
        scanf("%d", &op);

        if(!op)
            exit(0);
        
    }
    
    
    return 0;
}
