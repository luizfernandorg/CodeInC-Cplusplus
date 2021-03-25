#include <iostream>
#include <string>

#ifndef _GB_CLSS_
#define _GB_CLSS_
class GradeBook
{
    std::string courseName;
    public:
        explicit GradeBook(std::string name): courseName(name) {}
        void setCourseName(std::string name){
            courseName = name;
        }
        std::string getCourseName(){
            return courseName;
        }

        void displayMessage(){
            std::cout << "Welcome to the grade book for: " << getCourseName() << "!" << std::endl;
        }
};
#endif