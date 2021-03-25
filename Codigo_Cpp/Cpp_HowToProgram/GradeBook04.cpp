#include <iostream>
#include <string>

class GradeBook{
    std::string courseName; 
public: 
    // the constructor here use a member-initializer list, there is a ":" followed by the class's data-member with the new value for it
    // surrounded by parenthesis
    // **learn more about explicit keyword
    explicit GradeBook(std::string name): courseName(name) {}

    // bellow is defined all the object’s member functions that will be public
    void setCourseName(std::string name){
        courseName = name;
    }
    std::string getCourseName() const {
        return courseName;
    }
    void displayMessage() const {
        std::cout << "Welcome to the grade book for " << getCourseName() << "!" << std::endl;
    }
};

int main(){
    GradeBook gb1("CS101 Introduction to C++ Programming");
    GradeBook gb2("CS102 Data Structures in C++");

    std::cout << "gradeBook1 created for course: " << gb1.getCourseName() << std::endl;
    std::cout << "gradeBook2 created for course: " << gb2.getCourseName() << std::endl;
}