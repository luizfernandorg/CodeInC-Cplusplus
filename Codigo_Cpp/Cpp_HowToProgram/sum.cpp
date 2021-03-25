#include <iostream>

int main()
{
    int number1;
    int number2;
    int sum;

    std::cout << "Enter first number: ";
    std::cin >> number1;
    std::cout << "Enter second number: ";
    std::cin >> number2;

    sum = number1 + number2;

    std::cout << "Sum is: " << sum << std::endl;
}