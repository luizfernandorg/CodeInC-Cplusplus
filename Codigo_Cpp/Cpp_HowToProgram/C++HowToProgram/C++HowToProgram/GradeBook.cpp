#include <iostream>
#include <string>
#include <iomanip>
#include "GradeBook.h"

//setting GradeBook implementation.
//"::" is the scope resolution operator
//constructors
// generally we should initiate member-variables using member initializer
//GradeBook::GradeBook(std::string name): courseName(name) {} 
GradeBook::GradeBook(std::string course) { setCourseName(course); }

GradeBook::GradeBook ( const std::string& name, const std::array<int,students>& students) : courseName(name), testing(students) {}

GradeBook::GradeBook( const std::string& name, const std::array< std::array<int, tests>, students >& gradesArray )
    : courseName(name), grades(gradesArray) {}

// 3.11 exercise
GradeBook::GradeBook( std::string course, std::string instructor) {
    setCourseName(course);
    setInstructorName(instructor);
}

//member functions
void GradeBook::setCourseName(const std::string& name) {
    if(name.size() <= 25){
        courseName = name; // implemented example from the book    
    } else {
        courseName = name.substr(0,25);
        std::cerr << "Name \"" << name << "\" exceeds maximum length (25)\n"
                  << "Limiting courseName to first 25 characteres" 
                  << std::endl;
    }
}

std::string GradeBook::getCourseName() const {
    return courseName;
}

void GradeBook::displayMessage() const {
    
    // test if this course has an instructor
    // if not show a standard message
    // 3.11 exercise
    if(!getInstructorName().empty()){
        
        std::cout << "Welcome to the grade book for " 
                  << getCourseName() 
                  << ", This course is presented by: " 
                  << getInstructorName()
                  << "!" 
                  << std::endl;
    }else{
        std::cout << "Welcome to the grade book for " << getCourseName() << "!" << std::endl;    
    }
}

void GradeBook::processGrades() const {
    outputGrades();

    std::cout << std::setprecision(2) << std::fixed;

    std::cout << "\nLowest grade in the grade book is " << getMinimum() 
              << "\nHighest grade in the grade book is " << getMaximum() 
              << std::endl;
    /*
    std::cout << "\nClass average is " << getAverage() << std::endl;
    std::cout << "Lowest grade is " << getMinimum() << std::endl;
    */
    outputBarChart();
}

int GradeBook::getMinimum() const {
    int lowGrade = 100;

    for (auto const& student : grades) {
        for (auto const& grade : student) {
            if (grade < lowGrade)
                lowGrade = grade;
        }
    }
    /*
    for ( int grade : grades ){
        if (grade < lowGrade) {
            lowGrade = grade;
        }
    }
    */
    return lowGrade;
}

int GradeBook::getMaximum() const {
    int highGrade = 0;

    for (auto const& student : grades) {
        for (auto const& grade : student) {
            if (grade > highGrade)
                highGrade = grade;
        }
    }
    /*
    for (int grade : grades) {
        if (grade > highGrade) {
            highGrade = grade;
        }
    }
    */
    return highGrade;
}

double GradeBook::getAverage(const std::array< int, tests >& setOfGrades) const {
    int total = 0;

    for (int grade : setOfGrades) {
        total += grade;
    }

    return static_cast< double >( total ) / setOfGrades.size();
}

void GradeBook::outputBarChart() const {
    /*
    std::cout << "\nGrade distribution: " << std::endl;

    const size_t frequencySize = 11;
    std::array< uint32_t, frequencySize > frequency = {};

    for (int grade : grades) {
        ++frequency[grade / 10];
    }

    for (size_t count = 0; count < frequency.size(); ++count) {
        if (0 == count) {
            std::cout << "  0-9: ";
        }
        else if (10 == count) {
            std::cout << "  100: ";
        }
        else {
            std::cout << count * 10 << "-" << (count * 10) + 9 << ": ";
        }

        for (uint32_t stars = 0; stars < frequency[count]; ++stars) {
            std::cout << "*";
        }

        std::cout << std::endl;
    }
    */
    std::cout << "\nOverall grade distribution:" << std::endl;

    const size_t frequencySize = 11;

    std::array<uint32_t, frequencySize> frequency = {};

    for (auto const& student : grades) {
        for (auto const& test : student) {
            ++frequency[test / 10];
        }
    }
    for (size_t count = 0; count < frequencySize; ++count) {
        if (0 == count) {
            std::cout << "  0-9: ";
        }
        else if (10 == count) {
            std::cout << "  100: ";
        }
        else {
            std::cout << count * 10 << "-" << (count * 10) + 9 << ": ";
        }
        for (uint32_t stars = 0; stars < frequency[count]; ++stars) {
            std::cout << "*";
        }

        std::cout << std::endl;
    }
}

void GradeBook::outputGrades() const {
    std::cout << "\nThe grades are:\n\n";
    std::cout << "            ";

    for (size_t test = 0; test < tests; ++test) {
        std::cout << "Test " << test + 1 << "  ";
    }

    std::cout << "Average" << std::endl;

    for (size_t student = 0; student < grades.size(); ++student) {
        std::cout << "Student " << std::setw(2) << student + 1;

        for (size_t test = 0; test < grades[student].size(); test++) {
            std::cout << std::setw(8) << grades[student][test];
        }

        double average = getAverage(grades[student]);
        std::cout << std::setw(9) << std::setprecision(2) << std::fixed << average << std::endl;
    }
    /*
    for (size_t student = 0; student < grades.size(); ++student) {
        std::cout << "Student " << std::setw(2) << student + 1 << ": " << std::setw(3) << grades[student] << std::endl;
    }
    */
}

void GradeBook::determineClassAverage() const {
    
    // Initialization phase
    // as good practice put each variable in their own line, as also initialize it, and put a commentary if needed
    int total = 0; // will store the sum of all grades
    unsigned int gradeCounter = 0; // counter for controle the while loop
    int grade = 0;
    
    std::cout << "Enter grade or -1 to quit: ";
    std::cin >> grade;
    
    while ( grade != -1 ){
        total = total + grade;
        gradeCounter = gradeCounter + 1;
        
        std::cout << "Enter grade or -1 to quit: ";
        std::cin >> grade;
    }
    
    if( gradeCounter != 0 ){
        //calculate average of all grades entered
        double average = static_cast< double >(total) / gradeCounter;
        
        std::cout << "\nTotal of all " << gradeCounter << " grades entered is " << total << std::endl;
        
        //this line says to cout stream to proceed now with a precision of 2 after the decimal point on double and float numbers
        std::cout << std::setprecision( 2 ) << std::fixed;
        // this line now can show a double number correctly
        std::cout << "Class average is " << average << std::endl;
    } else {
        std::cout << "No grades were entered!" << std::endl;
    }
}

// 3.11 exercise
void GradeBook::setInstructorName( std::string name ){
    instructorName = name;
}

std::string GradeBook::getInstructorName() const {
    return instructorName;
}

void GradeBook::inputGrades(){
    /*
    int grade;
    std::cout << "Enter the letter grades." << std::endl << "Enter the EOF character to end input." << std::endl;

    while ( (grade = std::cin.get() ) != EOF ) {
        switch ( grade ){
            case 'A':
            case 'a':
                ++aCount;
                break;
            case 'B':
            case 'b':
                ++bCount;
                break;
            case 'C':
            case 'c':
                ++cCount;
                break;
            case 'D':
            case 'd':
                ++dCount;
                break;
            case 'F':
            case 'f':
                ++fCount;
                break;
            case '\n':
            case '\t':
            case ' ':
                break;
            default:
                std::cout << "Incorrect letter grade entered." << " Enter a new grade." << std::endl;
                break;
        }
    }*/
    int grade1;
    int grade2;
    int grade3;

    std::cout << "Enter three integer grades: ";
    std::cin >> grade1 >> grade2 >> grade3;

    maximumGrade = maximum(grade1, grade2, grade3);
}

void GradeBook::displayGradeReport() const {
    /*std::cout << "\n\nNumber of students who received each letter grade:"
              << "\nA: " << aCount
              << "\nB: " << bCount
              << "\nC: " << cCount
              << "\nD: " << dCount
              << "\nF: " << fCount
              << std::endl;
    */
    std::cout << "Maximum of grades entered: "<< maximumGrade << std::endl;
}

int GradeBook::maximum( int x, int y, int z) const{
    int maximumValue = x;

    if( y > maximumValue ){
        maximumValue = y;
    }
    if( z > maximumValue ){
        maximumValue = z;
    }
    return maximumValue;
}