#include <stdio.h>
#include <stdlib.h> // to use malloc
/*
 In this example we create an array with the amount 
 set for the user
 allocate the amount of memory necessary to insert the number in the array

*/
int main(int argc, char const *argv[])
{
    int array_amount = 0;

    // Get the amount of numbers will be inserted
    printf("How many numbers do you want to register: ");
    scanf("%d", &array_amount);

    // allocate the necessary memory for the array
    int *numbers = (int*) malloc(sizeof(int) * array_amount);
    if(numbers == NULL){
        printf("Error - The Program wasn't able to alloc memory! exiting program.");
        exit(1);
    }
    printf("\nWrite the number and click Enter on each number: \n");

    for(int index = 0; index < array_amount; index++){
        int number;
        scanf("%d", &number);
        *(numbers+index) = number;
    }

    printf("size of the array %d\n", sizeof(numbers));/* get 8 because is a pointer, and pointers only 
        point to the first element, to access the n element in the memory, use *(pointer+n) or array[n], n >= 0
        is impossible to track the amount of elements that the array can hold, so is need to use a variavel, ex. int counter;
        and increment that variable as we go inserting elements in the memory, all the elements will be positionate in sequence
    */

    // loop through the array to proof that the array hold the numbers
    for (int i = 0; i < array_amount; i++)
    {
        printf("%d\n", numbers[i]);
    }
    free(numbers);
    return 0;
}