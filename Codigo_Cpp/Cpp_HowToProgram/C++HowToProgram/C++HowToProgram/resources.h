#include <iostream>

// Chapter 2
#if 0
    //#### sum example
    void sum(){
        int number1 = 0;
        int number2 = 0;
        int sum = 0;
        
        std::cout << "Enter first number: ";
        std::cin >> number1;
        
        std::cout << "Enter second number: ";
        std::cin >> number2;
        
        sum = number1 + number2;
        std::cout << "Sum is: " << sum << std::endl;
    }
    
    //#### if statement
    void compare_if(){
        int number1 = 0;
        int number2 = 0;
        
        std::cout << "Enter two integers to compare: " << std::endl;
        std::cin >> number1 >> number2;
        
        if (number1 == number2)
            std::cout << number1 << " == " << number2 << std::endl;
        if (number1 != number2)
            std::cout << number1 << " != " << number2 << std::endl;
        if (number1 < number2)
            std::cout << number1 << " < " << number2 << std::endl;
        if (number1 > number2)
            std::cout << number1 << " > " << number2 << std::endl;
        if (number1 <= number2)
            std::cout << number1 << " <= " << number2 << std::endl;
        if (number1 >= number2)
            std::cout << number1 << " >= " << number2 << std::endl;
    }
    
    //#### (isn't in the book, only for test) Reference example
    void refe(){
        int a = 10;
        int& b = a; // this variable isn't really created, it is just a shortcut/an alias;
        b = 20;
        std::cout << &b << " " << &a << std::endl;
        std::cout << b << " " << a << std::endl;
    }
    //#### (isn't in the book, only for test) 
    //Using reference, no variable is created when this function is called
    /*
    void refTest(int& a){
        std::cout << &a << " " << a << std::endl;
    }*/
    // this version of the function above, we use pointer, a variabel is created when call this function,
    // and this parameter will store an address of the variabel passed to this function
    void refTest(int* a){
        std::cout << &a << " " << a << " " << *a << std::endl;
    }
    void callRefTest(){
        // when we dealing with a function that has a parameter that is a reference
        // we just give to that parameter a variable (lvalue) that store some value(rvalue), 
        // we can't give to parameter. a rvalue like 22 or "someString", because this values don't have memory address
        // this don't even works with parameters that is a pointer, pointer can store address of lvalue not rvalues
        int b = 232;
        std::cout << &b << std::endl;
        refTest(&b);// here as the parameter is a pointer we send to it an address of the vairble b
        // if the parameter is an alias, a reference, we just pass b to it, we can't pass as we said a lvalue
    }
    
    //#### (isn't in the book, only a test) Practice of linked list
    struct Node {
        int data = 0;
        Node* next = nullptr;
    };
    // function declaration / interface
    void display(Node* head);
    
    void create_Linked_List(){
    
        Node* start = new Node();
        Node* temp = nullptr;
        
        start->data = 1;
        temp = start;
        
        temp->next = new Node();
        temp = temp->next;
        
        temp->data = 2;
        temp->next = new Node();
        temp = temp->next;
        
        temp->data = 3;
        //temp->next == nullptr; // node's end
        
        display(start); // because this function was declared above now in this line is possible call the function definited bellow, 
                        //without the declaration is impossible to call the function bellow, the other way as to define the fuction display above this function
        delete[] start;
        delete[] temp;
    }
    // function definition
    void display(Node* head){
        if(head){
            std::cout << head->data << std::endl;
            display(head->next);
        }
    }
    
    //#### Gess a Number game
    #include <stdlib.h>
    #include <time.h>
    
    void gessNumber(){
        //int counter = 0;
        std::cout << "Guess game" << std::endl;
        std::cout << std::endl;
        std::cout << "Try to guess the number I'm thinking!" << std::endl;
        srand(time(0));
        int number = rand()%100;
        std::cout << number << std::endl;
        //while(1){
            // TODO: needed top implement
        //}
    }
#endif

// Chapter 3
#if 0
    //#### Use of GradeBook
    #include "GradeBook.h"
    /*
    void gradeBookGenerate(){
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
    */
    
    void gradeBookGenerate(){
        /*
        GradeBook gb1("CS101 Introduction to C++ Programming");
        GradeBook gb2("CS102 Data Structures in C++");
        GradeBook gb3("CS103 Algorithms in C++", "Luiz Fernando Ramos Garcia");
    
        gb1.displayMessage();
        gb2.displayMessage();
        gb3.displayMessage();
        
        std::cout << std::endl;
        
        std::cout << "gradeBook1 created for course: " << gb1.getCourseName() << std::endl;
        std::cout << "gradeBook2 created for course: " << gb2.getCourseName() << std::endl;
        
        gb1.setCourseName("CS101 C++ Programming");
        
        std::cout << std::endl;
        
        std::cout << "gradeBook1 created for course: " << gb1.getCourseName() << std::endl;
        
        std::cout << std::endl;
        
        gb1.displayMessage();
        gb2.displayMessage();
        gb3.displayMessage();*/
        GradeBook myGradeBook( "CS101 C++ Programming" );
        
        myGradeBook.displayMessage();
        myGradeBook.determineClassAverage();
    }
    
    //#### exercise 3.12 Account class
    class Account {
        int balance = 0;
    public:
        Account();
        explicit Account( int );
        void credit( int );
        void debit( int );
        int getBalance() const;
    };
    // definitions to members function
    Account::Account () {} // accepting default constructor despite the other constructors available
    Account::Account ( int accountBalance ){
        if(accountBalance >= 0){
            balance = accountBalance;
            std::cout << "Account was successfully created with the amount of $" << accountBalance << std::endl;
        }else{
            std::cerr << "Initial balance is invalid!" << std::endl;
        }
    }
    void Account::credit( int creditValue ){
        if(creditValue >= 0){
            balance += creditValue;
            std::cout << "it was successfully credited the amount of $" << creditValue << std::endl;
        }else{
            std::cerr << "It was passed an invalid value!" << std::endl;
        }
    }
    void Account::debit( int debitValue ) {
        if(debitValue > balance){
            std::cerr << "Debit amount exceeded account balance." << std::endl;
        } else {
            balance -= debitValue;
            std::cout << "it was successfully debited the amount of $" << debitValue << std::endl;
        }
    }
    int Account::getBalance() const {
        return balance;
    }
    //test the Account class
    void testAccount(){
        Account c1;
        c1.credit(1000);
        std::cout << "Current balance of c1 is: $" << c1.getBalance() << std::endl;
        c1.debit(500);
        std::cout << "Current balance of c1 is: $" << c1.getBalance() << std::endl;
        c1.debit(650);
        std::cout << "Current balance of c1 is: $" << c1.getBalance() << std::endl;
        
        std::cout << "============" << std::endl;
        
        Account c2(100);
        std::cout << "Current balance of c2 is: $" << c2.getBalance() << std::endl;
        c2.credit(50);
        std::cout << "Current balance of c2 is: $" << c2.getBalance() << std::endl;
        c2.debit(10);
        std::cout << "Current balance of c2 is: $" << c2.getBalance() << std::endl;
        c2.debit(600);
        std::cout << "Current balance of c2 is: $" << c2.getBalance() << std::endl;
    }
    
    //### exercise 3.13 Invoice class
    class Invoice {
        std::string number;
        std::string description;
        int quantity;
        int price;
    public:
        explicit Invoice( std::string, std::string, int, int );
        void setNumber ( std::string );
        void setDescription ( std::string );
        void setQuantity ( int );
        void setPrice ( int );
        
        std::string getNumber () const;
        std::string getDescriptinon () const;
        int getQuantity () const;
        int getPrice () const;
        int getInvoiceAmount () const;
    };
    // construtor definition
    Invoice::Invoice (std::string inv_number, std::string inv_description, int inv_quantity, int inv_price )
        : number(inv_number), description(inv_description), quantity(inv_quantity), price(inv_price) {}
    // setters members function definitions
    void Invoice::setNumber ( std::string inv_number ){
        number = inv_number;
    }
    void Invoice::setDescription ( std::string inv_description) {
        description = inv_description;
    }
    void Invoice::setQuantity ( int inv_quantity ) {
        quantity = inv_quantity;
    }
    void Invoice::setPrice ( int inv_price ) {
        price = inv_price;
    }
    //Getters members function definitions
    std::string Invoice::getNumber () const {
        return number;
    }
    std::string Invoice::getDescriptinon () const {
        return description;
    }
    int Invoice::getQuantity () const {
        return quantity;
    }
    int Invoice::getPrice () const {
        return price;
    }
    int Invoice::getInvoiceAmount () const {
        if(quantity < 0 || price < 0)
            return 0;
        return quantity * price;
    }
    
    void testInvoice(){
        Invoice inv1("ab12345", "Tv Samsung 4k", 12, 1250);
    
        std::cout << "Number: " << inv1.getNumber() << std::endl;
        std::cout << "Description: " << inv1.getDescriptinon() << std::endl;
        std::cout << "Quantity: " << inv1.getQuantity() << std::endl;
        std::cout << "Price: " << inv1.getPrice() << std::endl;
        std::cout << "Amount $" << inv1.getInvoiceAmount() << std::endl;
    
        std::cout << std::endl;
        inv1.setNumber("ab123456");
        inv1.setDescription("Tv Samsung 4k com conversor digital");
        inv1.setQuantity(125);
        inv1.setPrice(1100);
        
        std::cout << "Amount $" << inv1.getInvoiceAmount() << std::endl;
        
        std::cout << std::endl;
        
        Invoice inv2("ab34566", "Ventilador 7 velocidade", 123, 123);
        std::cout << "Amount $" << inv2.getInvoiceAmount() << std::endl;
        
        
    }
    
    //### exercise 3.14 Employee class
    class Employee {
        std::string name;
        std::string lastname;
        int salary; //monthly salary
    public:
        explicit Employee ( std::string, std::string, int );
        void setName( std::string );
        void setLastName( std::string );
        void setSalary( int );
        
        std::string getName();
        std::string getLastName();
        int getSalary();
    };
    Employee::Employee ( std::string emp_name, std::string emp_lastName, int emp_salary ) 
        : name(emp_name), lastname(emp_lastName), salary(emp_salary < 0 ? 0 : emp_salary) {}
    
    void Employee::setName ( std::string emp_name ){
        name = emp_name;
    }
    void Employee::setLastName ( std::string emp_lastName ) {
        lastname = emp_lastName;
    }
    void Employee::setSalary ( int emp_salary ) {
        salary = emp_salary < 0 ? 0 : emp_salary;
    }
    std::string Employee::getName () {
        return name;
    }
    std::string Employee::getLastName () {
        return lastname;
    }
    int Employee::getSalary () {
        return salary;
    }
    
    void testEmployee(){
        Employee emp1("Luiz", "Ramos", 2500);
        
        //test Getters
        std::cout << "First name: " << emp1.getName() << std::endl;
        std::cout << "Last name: " << emp1.getLastName() << std::endl;
        std::cout << "Yearly Salary: $" << emp1.getSalary()*12 << std::endl;
        
        std::cout << std::endl;
        
        //test Setters
        emp1.setName("Luiz");
        emp1.setLastName("Ramos");
    
        int salary = emp1.getSalary();
        int newSalary = salary+(0.1*salary);
    
        emp1.setSalary(newSalary);
        
        //test Getters
        std::cout << "First name: " << emp1.getName() << std::endl;
        std::cout << "Last name: " << emp1.getLastName() << std::endl;
        std::cout << "Yearly Salary: $" << emp1.getSalary()*12 << std::endl;
        
        std::cout << std::endl;
        
        Employee emp2("Fernando", "Garcia", 3600);
        
        salary = emp2.getSalary();
        newSalary = salary+(0.1*salary);
        
        emp2.setSalary(newSalary);
        
        //test Getters
        std::cout << "First name: " << emp2.getName() << std::endl;
        std::cout << "Last name: " << emp2.getLastName() << std::endl;
        std::cout << "Yearly Salary: $" << emp2.getSalary()*12 << std::endl;
    }
    
    //### exercise 3.15 Date class
    class Date {
        int month;
        int day;
        int year;
    public:
        explicit Date ( int, int, int );
        void setMonth ( int );
        void setDay ( int );
        void setYear ( int );
        int getMonth ();
        int getDay ();
        int getYear ();
        std::string displayDate ();
    };
    
    Date::Date ( int d_month, int d_day, int d_year): month( (d_month > 0 && d_month < 13) ? d_month : 1), day(d_day), year(d_year) {}
    
    void Date::setMonth ( int d_month ) {
        month = (d_month > 0 && d_month < 13) ? d_month : 1;
    }
    
    void Date::setDay ( int d_day ) {
        day = d_day;
    }
    
    void Date::setYear ( int d_year ) {
        year = d_year;
    }
    
    int Date::getMonth () {
        return month;
    }
    
    int Date::getDay () {
        return day;
    }
    
    int Date::getYear () {
        return year;
    }
    
    std::string Date::displayDate () {
        return std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year);
    }
    
    void testDate(){
        Date d1(11,30,2020);
        std::cout << "Month: " << d1.getMonth() << std::endl;
        std::cout << "Day: " << d1.getDay() << std::endl;
        std::cout << "Year: " << d1.getYear() << std::endl;
        std::cout << "Full date: " << d1.displayDate() << std::endl;
        
        Date d2(13,30,2020);
        
        std::cout << "Full date: " << d2.displayDate() << std::endl;
        
        d2.setMonth(5);
        d2.setDay(25);
        d2.setYear(1979);
    
        std::cout << "Full date: " << d2.displayDate() << std::endl;
        
    }
#endif

// for test proposal
#if 0
    //#### test for returning a reference (out the book)
    class Test{
        int age;
    public:
        explicit Test(int age): age(age) {}
        int& getAge(){
            std::cout << "Test age: " << &age << std::endl;
            return age;
        }
    };
    void testReturnRef(){
        Test p1(41);
        int& a = p1.getAge();
        std::cout << &a << std::endl;
        std::cout << a << std::endl;
        
        Test p2(34);
        int& b = p2.getAge();
        std::cout << &b << std::endl;
        std::cout << b << std::endl;
    }
#endif

// Chapter 4
#if 0
    void testNestedStatement() {
        // initializing variables in declarations
        unsigned int passes = 0;
        unsigned int failures = 0;
        unsigned int studentCounter = 1;
        
        // process 10 students using counter-controlled loop
        while ( studentCounter <= 10 ){
        	std::cout << "Enter result (1 = pass, 2 = fail): ";
        	int result = 0; // it accepts (1 = pass or 2 = fail)
        	std::cin >> result;
        
        	if ( result == 1 )
        		passes = passes + 1;
        	else
        		failures = failures + 1;
        	studentCounter = studentCounter + 1;
        }
        std::cout << "Passed " << passes << "\nFailed " << failures << std::endl;
        
        if ( passes > 8 )
        	std::cout << "Bonus to instructor!" << std::endl;
    }
    
    // Class for test the list initializer on objects
    class TestListInitializer {
        std::string name = "";
        int age = 0;
        float height = 0;
    public:
        //explicit TestListInitializer( std::string name, int age, float height) : name(name), age(age), height(height) {}
        TestListInitializer( std::string name, int age, float height) 
            : name(name), age(age), height(height) {}
        // ...
        void toString(){
            std::cout << "Name: " << name << std::endl;
            std::cout << "Age: " << age << std::endl;
            std::cout << "Height: " << height << std::endl;
        }
    };
    
    //Testing list initializer
    void testListInitializerCls() {
            TestListInitializer t1("Luiz Fernando", 41, 1.77);  // works fine with implicit and explicit constructors
            TestListInitializer t2{"Fernando Ramos", 34, 1.75}; // works fine with implicit and explicit constructors
            TestListInitializer t3 = {"Luiz Garcia", 28, 1.67}; // works fine with implicit constructors
            
            t1.toString();
            std::cout << std::endl;
            t2.toString();
            std::cout << std::endl;
            t3.toString();
    }
    
    void incrementDecrement() {
        int c = 5;
        std::cout << "c: " << c << std::endl;
        std::cout << "c: " << c++ << std::endl;
        std::cout << "c: " << c << std::endl;
        
        int b = 5;
        std::cout << "b: " << b << std::endl;
        std::cout << "b: " << ++b << std::endl;
        std::cout << "b: " << b << std::endl;
    }
    
    // Exercise 4.12
    void testExercise4_12(){
        unsigned int y = 0;
        unsigned int x = 0;
        unsigned int total = 0;
        
        while ( x <= 10 ){
            y = x * x;
            std::cout << y << std::endl;
            total += y;
            ++x;
        }
        std::cout << "Total is " << total << std::endl;
    }

    // perform all exercises in this chapter
#endif

/// chapter 5
#if 0
    #include <iomanip>
    #include <cmath>
    #include "GradeBook.h"

    void exWhileCounted(){
        unsigned int counter = 0;
        while ( counter <= 10 ){
            std::cout << counter++ << " ";
        }
    }
    
    void exforCounted(){
        for(unsigned int counter = 1; counter <= 10; counter++){
            std::cout << counter << " ";
        }
    }

    void forSumExe(){
        unsigned int total = 0;

        for (unsigned int counter = 2; counter <= 20; counter += 2)
            total += counter;
        
        std::cout << "Sum is " << total << std::endl;

        total = 0;

        // another way to use the for loop above
        for(unsigned int counter = 2; counter <= 20; total += counter, counter += 2);
        // avoid doing this, merging the loop body in the increment phase like above, it'll cause difficult to read and mantain
        std::cout << "Sum is " << total << std::endl;
    }
    
    void compoundInterest(){
        double amount; // amount on deposit at end of each year
        double principal = 1000.0; // initial amount before interest
        double rate = .05; // annual interest rate

        // display headers
        std::cout << "Year" << std::setw(21) << "Amount on deposit" << std::endl;

        // set floating-point number format
        std::cout << std::fixed << std::setprecision(2);

        // calculate amount on deposit for each of ten years
        for(unsigned int year = 1; year <= 10; ++year){
            // calculate new amount for specified year
            amount = principal * std::pow( 1.0 + rate, year);

            // display the year and the amount
            std::cout << std::setw(4) << year << std::setw(21) << amount << std::endl;
        }
    }

    void testDoWhile(){
        unsigned int counter = 1;
        
        do
        {
            std::cout << counter << " "; // Display counter
            ++counter;// increment
        } while (counter <= 10);
        std::cout << std::endl;
    }

    void testGradeBookChp5() {
        GradeBook myGradeBook("CS101 C++ Programming");
        myGradeBook.displayMessage();
        myGradeBook.inputGrades();
        myGradeBook.displayGradeReport();
    }

    void testBreak(){
        unsigned int count;

        for ( count = 1; count <= 10; ++count ){
            if ( count == 5 )
                break;
            std::cout << count << " ";
        }
        std::cout << "\nBroke out of loop at count = " << count << std::endl;
    }

    void breakTest(){
        unsigned int count;

        for(count = 1; count <= 10; ++count){
            if (count == 5){
                break;
            }
            std::cout << count << std::endl;
        }
        std::cout << "\nBroke out of loop at count = " << count << std::endl;
    }

    void continueTest(){
        for(unsigned int count = 1; count <= 10; count++){
            if ( count == 5 )
                continue;
            std::cout << count << " ";
        }
        std::cout << "\nUsed continue to skip printing 5" << std::endl;
    }

    void logicalOperators(){
        std::cout << std::boolalpha << "Logical AND (&&)"
                  << "\nfalse && false = " << ( false && false )
                  << "\nfalse && true = " << ( false && true )
                  << "\ntrue && false = " << ( true && false )
                  << "\ntrue && true = " << ( true && true )
                  << std::endl;
        std::cout << "Logical OR (||)"
                  << "\nfalse || false = " << ( false || false )
                  << "\nfalse || true = " << ( false || true )
                  << "\ntrue || false = " << ( true || false )
                  << "\ntrue || true = " << ( true || true )
                  << std::endl;
        std::cout << "Logical NOT (!)"
                  << "\n!false = " << ( !false )
                  << "\n!true = " << ( !true )
                  << std::endl;
    }

    // Exercises:
    // 5.2 A
    void sumOddNumbers(){
        unsigned int sum=0, count;
        for(count = 1; count <= 99; count++){
            if(count % 2){
                std::cout << count << std::endl;
                sum += count;
            }
        }
        std::cout << sum << std::endl;
    }
    
    // 5.2 B
    void printNumber(){
        double number = 333.546372;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << std::setw(15) << std::left << number; 

        std::cout << std::fixed << std::setprecision(2);
        std::cout << std::setw(15) << std::left << number;

        std::cout << std::fixed << std::setprecision(3);
        std::cout << std::setw(15) << std::left << number;
    }
    
    // 5.2 C
    void calculateRaise(){
        std::cout << std::fixed << std::setprecision(2);
        std::cout << std::left << std::setw(10) << std::pow(2.5,3);
    }
    
    // 5.2 D
    void print_With_While(){
        unsigned int x =1;
        while(x <= 20){
            std::cout << x;
            if(x % 5 == 0){
                std::cout << std::endl;
            }else{
                std::cout << '\t';
            }
            x++;
        }
    }
    
    // 5.2 E
    void print_With_for(){
        for(unsigned int x = 1; x <= 20; x++){
            std::cout << x;
            if(x % 5 == 0){
                std::cout << std::endl;
            }else{
                std::cout << '\t';
            }
        }
    }

    // exercise 5.5
    void sumInputs(){
        uint32_t qtdNumbers = 0;
        uint32_t sum = 0;
        uint32_t number = 0;

        std::cin >> qtdNumbers;
        for(uint32_t i = 1; i <= qtdNumbers; i++)
        {
            std::cin >> number;
            sum += number;
        }
        std::cout << sum << std::endl;
        std::cin.get();
    }

    // execise 5.6
    void calcAverage(){
        uint32_t sum = 0;
        uint32_t total = 0;
        uint32_t number = 0;

        for (;;){
            std::cin >> number;
            if(number != 9999)
            {
                sum += number;
                total++;
            } else {
                break;
            }
        }
        std::cout << (sum / total) << std::endl;
        std::cin.get();
    }

    /*
     * 5.8 (Find the Smallest Integer) Write a program that uses a for statement to find the smallest
     *     of several integers. Assume that the first value read specifies the number of values remaining.
     */
    void findSmallest(){
        uint32_t values = 0;
        uint32_t smallest = 0;
        uint32_t numberReaded = 0;

        std::cout << "How many numbers do you wanna check? ";
        std::cin >> values;

        for(uint32_t i = 0; i < values; i++){
            std::cin >> numberReaded;
            if(!i){
                smallest = numberReaded;
            } else if (numberReaded < smallest){
                smallest = numberReaded;
            }
        }
        std::cout << "The smallest one is: " << smallest;
        std::cin.get();
    }

    /*
     * 5.9 (Product of Odd Integers) Write a program that uses a for statement to calculate and print
     *   the product of the odd integers from 1 to 15.
     */
    void calcProduct(){
        uint32_t product = 1;
        for(uint32_t i = 1; i <= 15; i += 2)
        {
            product *= i;
        }
        std::cout << "The product of odd numbers from 1 to 15 is: " << product;
    }

    /*
     * 5.10 (Factorials) The factorial function is used frequently in probability problems. Using the
     *   definition of factorial in Exercise 4.34, write a program that uses a for statement to evaluate the factorials
     *   of the integers from 1 to 5. Print the results in tabular format. What difficulty might prevent
     *   you from calculating the factorial of 20?
     */
    void fatorial(){
        uint32_t fatorial = 1;
        for(uint32_t i = 1; i <= 5; i++){
            fatorial *= i;
            std::cout << fatorial << ( i == 5 ? "" : "\t");
        }
        
    }

    /*
     * 5.11 (Compound Interest) Modify the compound interest program of Section 5.4 to repeat its
     *      steps for the interest rates 5%, 6%, 7%, 8%, 9% and 10%. Use a for statement to vary the interest
     *      rate.
     */
    void compInterest(){
        double amount; // amount on deposit at end of each year
        double principal = 1000.0; // initial amount before interest
        // display headers
        std::cout << "Year" << std::setw( 21 ) << "Amount on deposit" << std::setw(21) << "Rated from" << std::endl;
        
        // set floating-point number format
        std::cout << std::fixed << std::setprecision( 2 );

        for ( uint32_t year = 1; year <= 2; ++year ){
            for( uint32_t rate = 5; rate <= 10; rate++){
                amount = principal * pow( 1.0 + ((double)rate)/100, year );
                // display the year and the amount
                std::cout << std::setw( 4 ) << year << std::setw( 21 ) << amount << std::setw(21) << (((double)rate)/100) << "%" << std::endl;
            }          
        }
    }
    /*
     *   5.12 (Drawing Patterns with Nested for Loops) Write a program that uses for statements to
     *       print the following patterns separately, one below the other. Use for loops to generate the patterns.
     *       All asterisks (*) should be printed by a single statement of the form cout << '*'; (this causes the
     *       asterisks to print side by side). [Hint: The last two patterns require that each line begin with an appropriate
     *       number of blanks. Extra credit: Combine your code from the four separate problems into
     *       a single program that prints all four patterns side by side by making clever use of nested for loops.]
     */
    void drawingPatterns(){
        int a,b,c,d,col,colCount;

        for(int y = 1; y <= 10; y++){
            a=1;
            b=10;
            c=1;
            d=10;
            col=1;
            colCount=1;
            for(int x = 1; x <= 40; x++){
                if(colCount > 10){
                    col++;
                    colCount = 1;
                }

                if(col == 1){
                    if(a <= y){
                        std::cout << "*";
                    }else{
                        std::cout << " ";
                    }
                    a++;
                }

                if(col == 2){
                    if(b >= y){
                        std::cout << "*";
                    }else{
                        std::cout << " ";
                    }
                    b--;
                }

                if(col == 3){
                    if(c >= y){
                        std::cout << "*";
                    }else{
                        std::cout << " "; 
                    }
                    c++;
                }
                
                if(col == 4){
                    if(d > y){
                        std::cout << " ";                        
                    }else{
                        std::cout << "*";
                    }
                    d--;
                }
                colCount++;
            }
            std::cout << std::endl;
        }
    }

    /*
     * 5.13 (Bar Chart) One interesting application of computers is drawing graphs and bar charts.
     *       Write a program that reads five numbers (each between 1 and 30). Assume that the user enters only
     *       valid values. For each number that is read, your program should print a line containing that number
     *       of adjacent asterisks. For example, if your program reads the number 7, it should print *******.
     */
    void barChart(){
        int number=0;
        std::cout << "Give a number or 0: ";
        std::cin >> number;
        while(number != 0){
            for(int i=0; i < number; i++){
                std::cout << "*";
            }

            std::cout << std::endl;
            std::cout << "Give a number or 0: ";
            std::cin >> number;
        }
        
    }
#endif

/// chapter 6
#if 0
    #include "GradeBook.h"

    void useGradeBook(){
        GradeBook myGradeBook("CS101 C++ Programming");

        myGradeBook.displayMessage();
        myGradeBook.inputGrades();
        myGradeBook.displayGradeReport();
        std::cin.get();
    }

    #include <iomanip>
    #include <cstdlib>
    
    void testRand(){
        for(uint32_t counter = 1; counter <= 20; ++counter){
            std::cout << std::setw(10) << (1 + std::rand() % 6);
            if( counter % 5 == 0){
                std::cout << std::endl;
            }
        }
    }
    
    void six_sizedDieLikelihood(){
        uint32_t frequency1 = 0;
        uint32_t frequency2 = 0;
        uint32_t frequency3 = 0;
        uint32_t frequency4 = 0;
        uint32_t frequency5 = 0;
        uint32_t frequency6 = 0;

        for( uint32_t roll = 1; roll <= 6000000; roll++ ){
            uint32_t face = 1 + rand() % 6;

            switch ( face )
            {
                case 1:
                    ++frequency1;
                    break;
                case 2:
                    ++frequency2;
                    break;
                case 3:
                    ++frequency3;
                    break;
                case 4:
                    ++frequency4;
                    break;
                case 5:
                    ++frequency5;
                    break;
                case 6:
                    ++frequency6;
                    break;
                default:
                    std::cout << "Program should never get here!";
            }
        }

        std::cout << "Face" << std::setw(13) << "Frequency" << std::endl;
        std::cout << "   1" << std::setw(13) << frequency1
                << "\n   2" << std::setw(13) << frequency2
                << "\n   3" << std::setw(13) << frequency3
                << "\n   4" << std::setw(13) << frequency4
                << "\n   5" << std::setw(13) << frequency5
                << "\n   6" << std::setw(13) << frequency6 << std::endl;
    }

    #include <ctime>
    void fig06_10_srand(){
        std::srand( static_cast<uint32_t>(time(0)) );

        for ( uint32_t counter = 1; counter <= 10; counter++ ){
            std::cout << std::setw(10) << ( 1 + rand() % 6 );
            if (counter % 5 == 0)
                std::cout << std::endl;
        }
        std::cin.get();
    }

    uint32_t RollDice(){
        uint32_t die1 = 1 + rand() % 6;
        uint32_t die2 = 1 + rand() % 6;

        uint32_t sum = die1 + die2;

        std::cout << "Player rolled " << die1 << " + " << die2 << " = " << sum << std::endl;
        return sum;
    }
    
    void fig06_11(){
        enum struct Status { CONTINUE, WON, LOST };
        std::srand( static_cast<uint32_t>( time( 0 ) ) );
        uint32_t myPoint = 0;
        Status gameStatus = Status::CONTINUE;
        uint32_t sumOfDice = RollDice();

        switch (sumOfDice)
        {
            case 7:
            case 11:
                gameStatus = Status::WON;
                break;
            case 2:
            case 3:
            case 12:
                gameStatus = Status::LOST;
                break;
            default:
                gameStatus = Status::CONTINUE;
                myPoint = sumOfDice;
                std::cout << "Point is " << myPoint << std::endl;
                break;
        }

        while ( Status::CONTINUE == gameStatus ){
            sumOfDice = RollDice();
            if ( sumOfDice == myPoint ){
                gameStatus = Status::WON;
            }else if ( sumOfDice == 7 ){
                gameStatus = Status::LOST;
            }
        }
        
        if ( Status::WON == gameStatus ){
            std::cout << "Player wins" << std::endl;
        }else{
            std::cout << "Player loses" << std::endl;
        }
    }

    #include <random>
    void fig06_12(){
        std::default_random_engine engine( static_cast<uint32_t>( time( 0 ) ) );
        std::uniform_int_distribution<uint32_t> randomInt(1, 6);

        for ( uint32_t counter = 1; counter <= 10; counter++ ){
            std::cout << std::setw(10) << randomInt( engine );

            if ( counter % 5 == 0 ){
                std::cout << std::endl;
            }
        }
    }

    // the example ain't in the book
    struct T{
        unsigned int a: 4; // set 4 bits for this variable
        int b : 8; // set 8 bits for this variable
    } teste;
    void useT(){
            teste.a = 15;
            //int c = sizeof(teste.a);// can use sizeof with bit-field
            std::cout << teste.a << std::endl;
    }
    
    // Fig. 6.13
    void useLocal(); // function prototype
    void useStaticLocal(); // function prototype
    void useGlobal(); // function prototype
    int x = 1;

    void fig6_13(){
        std::cout << "Global x in main is " << x << std::endl;
        int x = 5; // local variable
        std::cout << "local x in main's outer scope is " << x << std::endl;
        
        { // start new scope
            int x = 7; // hides both x in outer scope and global x
            std::cout << "local x in main's inner scope is " << x << std::endl;
        }
        
        std::cout << "local x in main's outer scope is " << x << std::endl;

        useLocal(); // useLocal has local x
        useStaticLocal(); // useStaticLocal has static local x
        useGlobal(); // useGlobal uses global x
        
        useLocal(); // useLocal reinitializes its local x
        useStaticLocal(); // static local x retains its prior value
        useGlobal(); // global x also retains its prior value
        
        std::cout << "\nlocal x main is " << x << std::endl;
    }

    // Fig. 6.14 declarations
    int square( int );

    void testsquare(){
        int a = 10;
        std::cout << a << " squared: " << square(a) << std::endl;
    }

    // fig. 6.18 Declarations
    void function1();
    void function2( void );

    void callfunctions(){
        function1();
        function2();
    }

    // Fig. 6.19 Definitions
    inline double cube( const double side ){
        return side * side * side;
    }

    void callCube(){
        double sideValue;
        std::cout << "Enter the side length of your cube: ";
        std::cin >> sideValue;

        std::cout << "Volume of cube with side " << sideValue << " is " << cube( sideValue ) << std::endl;
        std::cin.get();
    }

    // Fig. 6.20
    int squareByValue( int );
    void squareByReference( int& );

    void useSquare(){
        int x = 2;
        int z = 4;

        std::cout << "x = " << x << " before squareByValue\n";
        std::cout << "Value returned by squareByValue: " << squareByValue( x ) << std::endl;
        std::cout << "x = " << x << " after squareByValue\n";

        std::cout << "z = " << z << " before squareByReference\n";
        squareByReference( z );
        std::cout << "z = " << z << " after squareByReference\n";
    }

    // Fig. 6.21
    uint32_t boxVolume( uint32_t length = 1, uint32_t width = 1, uint32_t height = 1 );

    void useBoxVolume(){
        std::cout << "The default box volume is: " << boxVolume() << std::endl;
        std::cout << "The volume of a box with length 10, width 1 and height 1 is: " << boxVolume(10) << std::endl;
        std::cout << "The volume of a box with length 10, width 5 and height 1 is: " << boxVolume(10, 5) << std::endl;
        std::cout << "The volume of a box with length 10, width 5 and height 2 is: " << boxVolume(10, 5, 2) << std::endl;
    }

    // Fig. 6.22
    uint32_t a = 12;

    void unaryOperator(){
        uint32_t a = 23;
        std::cout << ::a << " " << a << std::endl;
    }

    // Fig. 6.23
    int square1 ( int y ){
        std::cout << "Square of int: " << y << " is " ;
        return y * y;
    }

    double square1 ( double y ){
        std::cout << "Square of double: " << y << " is " ;
        return y * y;
    }

    void useSquare1 (){
        std::cout << square1 ( 7 );
        std::cout << std::endl;
        std::cout << square1 ( 7.5 );
        std::cout << std::endl;
    }
    
    
    // Fig. 6.25
    template < typename T >
    T maximum( T value1, T value2, T value3 ){
        T maximumValue = value1;
        if( value2 > maximumValue )
            maximumValue = value2;
        
        if( value3 > maximumValue )
            maximumValue = value3;
        
        return maximumValue;
    }

    template < typename T >
    auto maximum2( T x, T y, T z ) -> decltype(x,y,z){
        T maximumValue = x;
        if( y > maximumValue )
            maximumValue = y;
        
        if( z > maximumValue )
            maximumValue = z;
        
        return maximumValue;
    }
    
    // Fig. 6.26
    void testeMaximum(){
        int int1, int2, int3;
        std::cout << "Input three integer values: ";
        std::cin >> int1 >> int2 >> int3;
        std::cout << "The maximum integer value is: " << maximum( int1, int2, int3 ) << std::endl;

        double double1, double2, double3;
        std::cout << "Input three double values: ";
        std::cin >> double1 >> double2 >> double3;
        std::cout << "The maximum double value is: " << maximum( double1, double2, double3 ) << std::endl;

        char char1, char2, char3;
        std::cout << "Input three characters: ";
        std::cin >> char1 >> char2 >> char3;
        std::cout << "The maximum character value is: " << maximum( char1, char2, char3 ) << std::endl;
        std::cin.get();
    }

    // 6.20 Recursion
    void factorialFor(){
        unsigned long factorial = 1;
        
        unsigned long number;
        std::cout << "Inform a number to see its factorial: ";
        std::cin >> number;

        for (uint32_t counter = number; counter >= 1; --counter){
            factorial *= counter;
        }

        std::cout << "Factorial of " << number << " is " << factorial << std::endl;
        std::cin.get();
    }
    
    // Fig. 6.28
    unsigned long factorial( unsigned long );

    void checkFactorial (){
        for ( uint32_t counter = 0; counter <= 10; counter++ ) {
            std::cout << std::setw( 2 ) << counter << " != " << factorial(counter) << std::endl;
        }
        std::cin.get();
    }

    // Fig. 6.29
    unsigned long fibonacci( unsigned long );
    void checkFibonacci () {
        for ( uint32_t counter = 0; counter <= 10; counter++){
            std::cout << "Fibonacci ( " << counter << " ) = " << fibonacci( counter ) << std::endl;
        }

        std::cout << "\nFibonacci (20) = " << fibonacci(20) << std::endl;
        std::cout << "Fibonacci (30) = " << fibonacci(30) << std::endl;
        std::cout << "Fibonacci (35) = " << fibonacci(35) << std::endl;
        std::cin.get();
    }
    
    // Fig. 6.31
    unsigned long factorialFor(uint32_t number){
        unsigned long factorial = 1;
        
        for (uint32_t counter = number; counter >= 1; --counter){
            factorial *= counter;
        }

        return factorial;
    }

    void checkFactorialFor(){
        for(uint32_t counter = 0; counter <= 10; counter++){
            std::cout << std::setw(2) << counter << "!= " << factorialFor(counter) << std::endl;
        }
        std::cin.get();
    }
#endif

/// chapter 7
#if 1
    #include "GradeBook.h"
    #include <iomanip>
    #include <array>
    #include <random>
    #include <string>
    #include <algorithm>
    #include <ctime>
    #include <cstddef> //size_t

    // Fig. 7.3
    void exampleArray(){
        std::array< int, 5 > n;
        //int c[5]{1,2,3,4,5}; // another way to declare and initiate an array
        //int b[5];

        for( size_t i = 0; i < n.size(); i++ ){
            n[i] = 0;
        }

        std::cout << "Element" << std::setw(13) << "Value" << std::endl;

        for( size_t j = 0; j < n.size(); j++ ){
            std::cout << std::setw(7) << j << std::setw(13) << n[j] << std::endl;
        }
        std::cin.get();
    }
   
    // Fig. 7.8
    void sumArray(){
        const size_t arraySize = 4;
        std::array< int, arraySize > a = { 10, 20, 30, 40 };
        int total = 0;

        for ( size_t i = 0; i < a.size(); i++ ){
            total += a[ i ];
        }
        std::cout << "Total of array elments: " << total << std::endl;
        std::cin.get();
    }

    // Fig. 7.9
    void gradeDistribution(){
        const size_t arraySize = 11;
        std::array< uint32_t, arraySize > n = { 0,0,0,0,0,0,1,2,4,2,1 };

        std::cout << "Grade distribution: " << std::endl;

        for( size_t i = 0; i < n.size(); ++i ){

            if( 0 == i ){
                std::cout << "  0-9: ";
            } else if ( 10 == i ){
                std::cout << "  100: ";
            } else {
                std::cout << i * 10 << "-" << ( i * 10 ) + 9 << ": ";
            }

            for( uint32_t stars = 0; stars < n[ i ]; ++stars ){
                std::cout << "*";
            }
            
            std::cout << std::endl;
        }
        std::cin.get();
    }

    // Fig. 7.10
    void dieRolling(){
        std::default_random_engine engine( static_cast<uint32_t>(time(0)) );
        std::uniform_int_distribution<uint32_t> randomInt( 1, 6 );

        const size_t arraySize = 7;
        std::array< uint32_t, arraySize > frequency = {};

        for ( uint32_t roll = 1; roll <= 6000000; roll++ ){
            frequency[ randomInt( engine ) ]++;
        }

        std::cout << "Face" << std::setw( 13 ) << "Frequency" << std::endl;

        for ( size_t face = 1; face < frequency.size(); face++ ) {
            std::cout << std::setw( 4 ) << face << std::setw( 13 ) << frequency[ face ] << std::endl;
        }
        std::cin.get();
    }

    // Fig. 7.11
    void pollAnalysis(){
        const size_t responseSize = 20;
        const size_t frequencySize = 6;

        const std::array< uint32_t, responseSize > responses = { 1, 2, 5, 4, 3, 5, 2, 1, 3, 1, 4, 3, 3, 3, 2, 3, 3, 2, 2, 5 };
        std::array< uint32_t, frequencySize > frequency = {};

        for ( size_t answer = 0; answer < responses.size(); answer++ ){
            ++frequency[ responses [ answer ] ];
        }

        std::cout << "Rating" << std::setw( 7 ) << "Frequency" << std::endl;

        for ( size_t rating = 1; rating < frequency.size(); ++rating ) {
            std::cout << std::setw( 6 ) << rating << std::setw( 17 ) << frequency[ rating ] << std::endl;
        }

        std::cin.get();
    }

    // Fig. 7.12
    void staticArrayInit();
    void automaticArrayInit();
    const size_t arraySize = 3;

    void useArraysInt() {
        std::cout << "First call to each function:\n";
        staticArrayInit();
        automaticArrayInit();
        
        std::cout << "\n\nSecond call to each function:\n";
        staticArrayInit();
        automaticArrayInit();
        std::cout << std::endl;
    }
    
    // Fig. 7.13
    void range_Based() {
        std::array< int, 5 > items = { 1,2,3,4,5 };

        std::cout << "items before modification: ";
        for (int item : items) {
            std::cout << item << " ";
        }

        // modificate its values
        for (int& itemRef : items) {
            itemRef *= 2;
        }

        std::cout << "\nitems after modification: ";
        for (int item : items) {
            std::cout << item << " ";
        }

        std::cout << std::endl;
    }

    // Fig. 7.17
    void useNewGradebook() {
        const std::array<int, GradeBook::students> grades = { 87, 68, 94, 100, 83, 78, 85, 91, 76, 87 };

        std::string courseName = "CS101 Introduction to C++ Programming";

        GradeBook myGradeBook(courseName, grades);
        myGradeBook.displayMessage();
        myGradeBook.processGrades();
    }

    // Fig. 7.18
    void sortSearch() {
        const size_t arraySize = 7;

        std::array<std::string, arraySize> colors = { "red", "orange", "yellow", "green", "blue", "indigo", "violet" };

        std::cout << "Unsorted array:\n";
        for (std::string color : colors) {
            std::cout << color << " ";
        }
        
        std::sort(colors.begin(), colors.end());

        std::cout << "\nSorted array:\n";
        for (std::string item : colors) {
            std::cout << item << " ";
        }

        bool found = std::binary_search(colors.begin(), colors.end(), "indigo");

        std::cout << "\n\n\"indigo\" " << (found ? "was" : "was not") << " found in colors" << std::endl;

        found = std::binary_search(colors.begin(), colors.end(), "cyan");

        std::cout << "\"cyan\"" << (found ? "was" : "was not") << " found in colors" << std::endl;
    }

    // Fig. 7.20
    const size_t rows = 2;
    const size_t columns = 3;
    void printArray(const std::array< std::array<int, columns>, rows>&);

    void multidimensionalArray() {
        std::array< std::array< int, columns>, rows> array1 = { 1, 2, 3, 4, 5, 6 };
        std::array< std::array< int, columns>, rows> array2 = { 1, 2, 3, 4, 5 };

        std::cout << "Values in array1 by row are: " << std::endl;
        printArray(array1);

        std::cout << "\nValues in array2 by row are: " << std::endl;
        printArray(array2);
    }

    // Fig. 7.24
    void use_newGradebook(){
        std::array< std::array< int, GradeBook::tests>, GradeBook::students> grades = {
            87, 96, 70,
            68, 87, 90,
            94, 100, 90,
            100, 81, 82,
            83, 65, 85,
            78, 87, 65,
            85, 75, 83,
            91, 94, 100,
            76, 72, 84,
            87, 93, 73
        };
        GradeBook myGradeBook("CS101 Introdution to C++ Programming", grades);
        myGradeBook.displayMessage();
        myGradeBook.processGrades();
        std::cin.get();
    }
    
    // Fig. 7.25
    #include <vector>
    #include <stdexcept>
    void outputVector( const std::vector<int>& );
    void inputVector( std::vector<int>& );

    void mainVector(){
        std::vector<int> integers1(7);
        std::vector<int> integers2(10);
        
        std::cout << "Size of vector integers1 is " << integers1.size() << "\nvector after initialization:" << std::endl;
        outputVector(integers1);

        std::cout << "Size of vector integers2 is " << integers2.size() << "\nvector after initialization:" << std::endl;
        outputVector(integers2);

        std::cout << "\nEnter 17 integers:" << std::endl;
        inputVector( integers1 ); // input 7 intergers
        inputVector( integers2 ); // input 10 integers

        std::cout << "\nAfter input, the vectors contain:\n" << "integers1:" << std::endl;
        outputVector( integers1 );
        std::cout << "integers2:" << std::endl;
        outputVector( integers2 );

        std::cout << "\nEvaluating: integers1 != integers2" << std::endl;
        if ( integers1 != integers2)
            std::cout << "integers1 and integers2 are not equal" << std::endl;

        std::vector<int> integers3(integers1);
        
        std::cout << "\nSize of vector integers3 is " << integers3.size() << "\nvector after initialization:" << std::endl;
        outputVector(integers3);

        std::cout << "\nAssigning integers2 to integers1:" << std::endl;
        integers1 = integers2;

        std::cout << "integers1" << std::endl;
        outputVector(integers1);
        
        std::cout << "integers2" << std::endl;
        outputVector(integers2);

        std::cout << "\nEvaluating: integers1 != integers2" << std::endl;
        
        if (integers1 != integers2)
            std::cout << "integers1 and integers2 are not equal" << std::endl;
        
        std::cout << "\nintegers1[5] is " << integers1[5] << std::endl;
        
        std::cout << "\n\nAssigning 1000 to integers1[5]" << std::endl;
        integers1[5] = 1000;
        std::cout << "integers1:" << std::endl;
        outputVector(integers1);

        try{
            std::cout << "\nAttempt to display integers1.at(15)" << std::endl;
            std::cout << integers1.at(15) << std::endl;
        } catch ( std::out_of_range &ex ){
            std::cerr << "An exception accured: " << ex.what() << std::endl;
        }

        std::cout << "\nCurrent integers3 size is: " << integers3.size() << std::endl;
        integers3.push_back(1000);// add 1000 to the vector's end
        std::cout << "New integers3 size is: " << integers3.size() << std::endl;
        std::cout << "integers3 now contains: ";
        outputVector(integers3);
        
        std::cin.get();
    }

    // Fig. 8.4
    void usingPointers() {
        int a = 7;
        int* aPtr = &a;

        std::cout << "The address of a is " << &a << "\nThe value of aPtr is " << aPtr << std::endl;
        std::cout << "The value of a is " << a << "\nThe value of *aPtr is " << *aPtr << std::endl;
    }

    // Fig. 8.7
    void cubeByReference(int*);
    void useCubeByReference() {
        int number = 5;
        std::cout << "The original value of number is " << number << std::endl;
        cubeByReference(&number);
        std::cout << "The new value of number is " << number << std::endl;
    }
#endif