/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int numbers[] = { 2,5,10,6,3,1,18,14,4,7,9,8,11,23,12 };
    
    int * n_ptr = numbers;
    
    int length = sizeof(numbers)/sizeof(numbers[0]);
 
    for(int x = 0, y = x; x < length && y < length; y++){
        if(*(n_ptr+x) > *(n_ptr+y)){
            int tmp = *(n_ptr+y);
            *(n_ptr+y) = *(n_ptr+x);
            *(n_ptr+x) = tmp;
        }
        if(y == length-1){
            x++;
            y = x;
        }
    }
    
    for(int x = 0; x < length; x++)
        printf("%d\n", numbers[x]);

    return 0;
}




