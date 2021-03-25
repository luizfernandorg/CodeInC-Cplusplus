#include <iostream>

// example of a class definition, 
// declare with capital letters on each word is know as Pascal case,
// because of Pascal programming language
class GradeBook{
private: // private here is optional because anything outside a public block is a private in a class by default 
    // this member only can be accessed by public or other private members
    static void static_Member() { 
        std::cout << "showing this message from static private member" << std::endl;
    }
    static void call_Static_Private_Member(){
        std::cout << "call_static_private_member was called!" << std::endl;
        static_Member();
    }
    int age;
public: // this is an access specifier
    static void to_String(){
        // accessing a static member in private block up there
        // in case the need to access a object member private or public non-static member is necessary to use this keyword
        call_Static_Private_Member();
        std::cout << "This is a static public member, can be accessed without need to declare a object" << std::endl;
    }
    //for convention, functions member use camel case style on its name
    // const used after () tells to compilter that this method can't modifty the object, like properties
    void displayMessage() const {
        //age = 10;
        static_Member();
        std::cout << "Welcome to the Grade Book! The age is " << this->age << std::endl;
    }
}; // final definition of GradeBook, here it's always necessary to use ";"

int main(){
    //this line below can't happen, only an object of Gradebook, can access a public non-static member
    //GradeBook::displayMessage(); 
    GradeBook::to_String();
    GradeBook myGradeBook;
    myGradeBook.displayMessage();
}