#include <stdio.h>

int main(){
    double num1;
    double num2;
    char op;

    printf("Digite o primeiro número: ");
    scanf("%lf", &num1);
    printf("Digite o operador: ");
    scanf(" %c", &op);
    printf("Digite o segundo número: ");
    scanf("%lf", &num2);

    if(op == '+'){ // '' é usado para um caracter e "" é usado quando representamos um grupo de caracteres
        printf("%.2f", num1 + num2);   
    } else if ( op == '-'){
        printf("$.2f", num1 - num2);
    } else if ( op == '/') {
        printf("%.2f", num1 / num2);
    } else if ( op == '*') {
        printf("%.2f", num1 * num2);
    } else {
        printf("Você digitou um algo errado, garanta que você digitou os número corretos ou um operador válido");
    }
    return 0;
}