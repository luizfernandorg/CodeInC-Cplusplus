#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    char c;

    n = (int) 'A';
    c = (char) n;
    printf("%d\n", n);
    printf("%c\n", n);
    printf("%c\n", c);
    printf("%d\n", c);
    return 0;
}

