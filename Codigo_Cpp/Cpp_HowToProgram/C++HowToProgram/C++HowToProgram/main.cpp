#include "resources.h"

int x = 1;

int main()
{
    // Execute examples taken from the Book C++ How To Program
    useCubeByReference();

    // continuing on page 288
    return 0;
}

// Fig. 6.13
// definitions for declarations in resources.h
void useLocal(){
    int x = 25;
    std::cout << "\nlocal x is " << x << " on entering useLocal" << std::endl;
    ++x;
    std::cout << "local x is " << x << " on exiting useLocal" << std::endl;
} // useLocal has local x

// useStaticLocal initializes static local variable x only the
// fist time the function is called; value of x is saved
// between calls to this function
void useStaticLocal(){
    static int x = 50; // initialized first time useStaticLocal is called
    std::cout << "\nlocal static x is " << x << " on entering useStaticLocal" << std::endl;
    ++x;
    std::cout << "local static x is " << x << " on exiting useStaticLocal" << std::endl;
} // useStaticLocal has static local x

// useGlobal modifies global variable x during each call
void useGlobal(){
    std::cout << "\nglobal x is " << x << " on entering useGlobal" << std::endl;
    x *= 10;
    std::cout << "global x is " << x << " on exiting useGlobal" << std::endl;
} // useGlobal uses global x

// Fig. 6.14
// definitions for declarations in resources.h
int square( int x ){
    return x * x;
}

// Fig. 6.18
void function1() {
    std::cout << "function1 takes no arguments" << std::endl;
}

void function2( void ) {
    std::cout << "function2 also takes no arguments" << std::endl;
}

// Fig. 6.20
int squareByValue( int number ){
    return number *= number;
}

void squareByReference( int& number ){
    number *= number;
}

// Fig. 6.21
uint32_t boxVolume( uint32_t length, uint32_t width, uint32_t height ){
    return length * width * height;
}

// Fig. 6.28
unsigned long factorial( unsigned long number ){
    if( number <= 1){
        return 1;
    } else {
        return number * factorial ( number -1 );
    }
}

// Fig. 6.29
unsigned long fibonacci( unsigned long number ){
    if( ( number == 0 ) || ( number == 1 ) ){
        return number;
    } else {
        return fibonacci( number - 1 ) + fibonacci( number - 2 );
    }
}

// Fig. 7.12
void staticArrayInit() {
    static std::array< int, arraySize > array1;

    std::cout << "\nValues on entering staticArrayInit:" << std::endl;

    for (size_t i = 0; i < array1.size(); i++) {
        std::cout << "array1[" << i << "] = " << array1[i] << " ";
    }

    std::cout << "\nValues on exiting staticArrayInit:\n";

    for (size_t j = 0; j < array1.size(); j++) {
        std::cout << "array1[" << j << "] = " << (array1[j] += 5) << " ";
    }
}

void automaticArrayInit() {
    std::array< int, arraySize > array2 = { 1,2,3 };

    std::cout << "\n\nValues on entering automaticArrayInit:" << std::endl;

    for (size_t i = 0; i < array2.size(); i++) {
        std::cout << "array2[" << i << "] = " << array2[i] << " ";
    }

    std::cout << "\nValues on exiting automaticArrayInit:\n";

    for (size_t j = 0; j < array2.size(); j++) {
        std::cout << "array2[" << j << "] = " << (array2[j] += 5) << " ";
    }
}

// Fig. 7.20
void printArray(const std::array< std::array<int, columns>, rows>& arrayValue) {
    for (auto const& row : arrayValue) {
        for (auto const& element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

// Fig. 7.25
void outputVector( const std::vector<int>& array) {
    for(int item : array){
        std::cout << item << " ";
    }
    std::cout << std::endl;
}
void inputVector( std::vector<int>& array) {
    for(int& item : array){
        std::cin >> item;
    }
}

void cubeByReference(int* ptr)
{
    *ptr = *ptr * *ptr * *ptr;
}
