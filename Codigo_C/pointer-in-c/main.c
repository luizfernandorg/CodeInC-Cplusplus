
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[4][4] = {
        {2,3,4,5},
        {6,7,8,9},
        {10,11,12,13},
        {14,15,16,17},
    };
 
    int * allocArray = (int *)malloc(sizeof(int) * 10);
    printf("sizeof(int) = %ld - sizeof(int*) = %ld - sizeof(int)*10 = %ld\n", sizeof(int), sizeof(int*), sizeof(int)*10);
    if(allocArray == NULL)                     
    {
        printf("Error! memory not allocated.");
        exit(0);
    }
    allocArray = (int *)realloc(allocArray, sizeof(int) * 10);
    if(allocArray == NULL)                     
    {
        printf("Error! memory not allocated.");
        exit(0);
    }
    int* pArray = &array[0][0];

    int a = 1;
    int* b = &a;
    printf("b has this address %p and this is its value %p, a has this address %p and this is its value %d", &b , b, &a, a );

    free(b);
    free(pArray);
    free(allocArray);
    
    /*
    for(int i = 0; i < sizeof(array[0]); i++){
        printf("%d\n", *(pArray+i));
    }*/

    return 0;
}



