#include <iostream>
#include <stdlib.h>
#include <time.h>

int main(){
    //int counter = 0;
    std::cout << "Guess game" << std::endl;
    std::cout << std::endl;
    std::cout << "Try to guess the number I'm thinking!" << std::endl;
    srand(time(0));
    int number = rand()%100;
    std::cout << number << std::endl;
    //while(1){

    //}
}