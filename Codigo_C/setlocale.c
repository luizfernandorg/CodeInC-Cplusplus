#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Portugues");
    printf("Olá chão, cão, avô, até, à\n");
    return 0;
}
