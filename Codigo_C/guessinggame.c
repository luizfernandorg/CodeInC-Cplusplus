#include <stdio.h>
#include <stdlib.h>

int main(){
    int secretNumber = 5;
    int guess;
    int guessCount = 0;

    while (guess != secretNumber)
    {
        printf("Enter a number: ");
        scanf("%d", &guess);
        guessCount++;
    }
    printf("You win with %d guesses!", guessCount);
    return 0;
}