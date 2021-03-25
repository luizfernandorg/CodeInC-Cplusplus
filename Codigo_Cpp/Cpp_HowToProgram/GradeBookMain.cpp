#include <iostream>
#include "GradeBook.h"

int main(){
    GradeBook g1("CS101 Introduction to C++ Programming");
    GradeBook g2("CS102 Data Structures in C++");

    std::cout << "Gradebook 1 created for course: " << g1.getCourseName() << std::endl;
    std::cout << "Gradebook 2 created for course: " << g2.getCourseName() << std::endl;
}