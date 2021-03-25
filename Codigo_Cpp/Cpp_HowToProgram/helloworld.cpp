#include <iostream>

using namespace std; // avoid use this, this can cause problems if two or more namespaces have the same name inside

int main(){
    std::cout << sizeof(int) << std::endl;
    cout<< "Welcome\n"; // call cout this way is not a good practice
    std::cout << "Hello World!" << std::endl; // always use this format
    std::cout << "this is my first program in C++\n"; // this is another way to use cout without std::endl, 
                                                      // using only \n in the string
    std::cin.get(); // or this way with cin
    return 0; // this line is optional, even if the program 
                // reach the next line that finishes the function
                // without the "return" statement will assume that
                // the program ended successfully
}