#pragma once
#include <iostream>
#include <string>
#include <array>

#ifndef _GB_CLSS_
#define _GB_CLSS_

//setting GradeBook interface
class GradeBook{
public:
    static const size_t students = 10;
    static const size_t tests = 3;

private:
    
    std::string courseName;
    std::array< std::array<int, tests>, students > grades = {};
    std::array< int, students> testing = {};

    std::string instructorName = "";// exercise 3.11, in this data-member ,rather than use NULL as value, what is not acceptable for type string, 
    // assing an empty value to be abble to test using (var != ""), as NULL value (var != NULL) will not work
    int maximumGrade = 0;
    unsigned int aCount = 0;
    unsigned int bCount = 0;
    unsigned int cCount = 0;
    unsigned int dCount = 0;
    unsigned int fCount = 0;
public: 
    
    // the constructor here uses a member-initializer list, there is a ":" followed by the class's data-member with the new value for it

    // surrounded by parenthesis
    // explicit GradeBook( std::string name ): courseName(name), instructorName("") {}
    
    // this tells to the compiler that only is acceptable to explicit call to this cont constructor, none type convertions are acceptable

    // this declarations parameters name are optionl
    explicit GradeBook( std::string );
    
    GradeBook ( const std::string&, const std::array<int,students>& );

    GradeBook ( const std::string&, const std::array<std::array<int, tests>, students>& );

    // exercise 3.11
    explicit GradeBook( std::string, std::string );
    
    // bellow is defined all the object’s member functions that will be public
    void setCourseName( const std::string& );

    std::string getCourseName() const;
    
    void displayMessage() const;

    void processGrades() const;
    int getMinimum() const;
    int getMaximum() const;
    double getAverage(const std::array< int, tests >&) const;
    void outputBarChart() const;
    void outputGrades() const;

    void inputGrades();
    void displayGradeReport() const;
    int maximum( int, int, int ) const;
    
    // Exercise
    void determineClassAverage() const;
    
    // exercise 3.11
    void setInstructorName( std::string );
    std::string getInstructorName() const;
};
#endif