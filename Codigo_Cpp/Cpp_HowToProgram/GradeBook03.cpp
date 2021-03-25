#include <iostream>
#include <string>

class GradeBook{
private: // this is optional, anything out of public or protected access specifier are private by default in class definition
    // all properties declarations that are private can be declare here or can be declare in a access specifier private:
    std::string courseName; // declaring a data member as private, is known as data hiding, and only member functions of this class
        // ... can access this property
public: 
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

    
    GradeBook myGradeBook;
    
    std::string nameOfCourse = myGradeBook.getCourseName();

    if(nameOfCourse != "")
        std::cout << "Initial course name " << nameOfCourse << std::endl;
    else
        std::cout << "There is no course name defined!" << std::endl;
    
    std::cout << "Please enter the course name: " << std::endl;
    std::getline(std::cin, nameOfCourse); //getline allow us to read a full line including blanks
    
    myGradeBook.setCourseName(nameOfCourse);

    std::cout << std::endl;

    myGradeBook.displayMessage();
}