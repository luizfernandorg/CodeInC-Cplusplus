#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dos.h>

struct Veiculo
{
    /* data */
    char placa[8];// xxx-nnn, neste caso ao inserir um valor deverá ser informado o valor \0 de fim de linha, 
                    //então ao invés de 7 será 8, sete posições da string e uma posição para o caracter de final de linha
} veiculo;

struct Student {
    char name[50];
    char major[50];
    int age;
    double gpa;
};
struct date
{
    int dia;
    int mes;
    int ano;
} date;

int main(){
    struct Student student1;

    student1.age = 22;
    student1.gpa = 3.2;

    strcpy( student1.name, "Luiz Fernando");
    strcpy( student1.major, "Computer Science");

    printf("%f\n", student1.gpa);

    ///veiculo.placa = "xxx-123\0";// não functiona pois estamos lidando com um array de caracteres, 
    // neste caso o ideal é usar strcpy(*variable, string)

    strcpy(veiculo.placa, "xxx-123");
    
    printf("Sua placa é %s", veiculo.placa);

    return 0;
}