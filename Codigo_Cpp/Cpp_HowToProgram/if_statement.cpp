#include <iostream>

int main(){
    int number1 = 0;
    int number2 = 0;
    
    std::cout << "Enter two integers to compare: " << std::endl;
    std::cin >> number1 >> number2;
    
    if (number1 == number2)
        std::cout << number1 << " == " << number2 << std::endl;
    if (number1 != number2)
        std::cout << number1 << " != " << number2 << std::endl;
    if (number1 < number2)
        std::cout << number1 << " < " << number2 << std::endl;
    if (number1 > number2)
        std::cout << number1 << " > " << number2 << std::endl;
    if (number1 <= number2)
        std::cout << number1 << " <= " << number2 << std::endl;
    if (number1 >= number2)
        std::cout << number1 << " >= " << number2 << std::endl;
    
    return 0;
}