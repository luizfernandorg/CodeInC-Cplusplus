#include <iostream>
#include <string>

class GradeBook{
public: 
    void displayMessage(std::string courseName) const {
        std::cout << "Welcome to the grade book for " << courseName << std::endl;
    }
};

int main(){

    std::string nameOfCourse;
    GradeBook myGradeBook;

    std::cout << "Please enter the course name: " << std::endl;
    //std::cin >> nameOfCourse; // this works like scanf in C only get one word ignoring after the first blank space
    std::getline(std::cin, nameOfCourse); //getline allow us to read a full line including blank space
    std::cout << std::endl;

    myGradeBook.displayMessage(nameOfCourse);
}