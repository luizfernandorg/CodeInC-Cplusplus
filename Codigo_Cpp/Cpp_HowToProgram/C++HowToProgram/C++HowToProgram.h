/*
A C++ Programs go through six phases: Edit, Preprocess, Compile, Link,
load and execute.
1) Edit:
        Edit the file(Source code) in the text editor or IDE extensions used by the 
        source code: .cpp, .cxx, .cc, .C (C in uppercase to indicate this is a C++ file) 
        in the compiler documentation there is an explanation for which extension it use.
2) Preprocessing:
        Preprocessing are directives given by the source code to the compiler, that indicates some manipulations are necessary
        Like the #include directive that indicates to the compiler to replace that directive by the source code in headers and C++ code
3) Compile:
        Converte a C++ source code to an Object
4) Linking:
        In the link process all the headers and source codes, used in the project, are put together to generate one single 
        the file that is the program itself, and executable software
5) Load:
        When the program is load, it is put in memory and also the libraries used by the software.
6) Execute:
        The CPU executes the program one instruction at a time. Some errors can occur in some moments than is a need to edit the code e go through all the processes again.
        C++ have to input and output data, to input data, use the std::cin >> ... (directing normally to keyboard, but can be redirected to another device)
        C++ output data using the std::cout << ... (normally the keyboard, but also can redirect to another device) to print an error can be used std::cerr


When the program runs then an error occurs is called a "Runtime Error" or "Execution-Time Error"
        
"Fatal Runtime Error" cause program to crash(terminate)


"Nonfatal Runtime Error", the program executes but with some possible wrong results


std is a namespace in C++ and cout, cin and cerr are names that belong to std namespace
this way to use one of those names we need to do this:


        std::cout
        std::cin
        std::cerr


but using the keyword using we can avoid use std::cout, like so:
        using namespace std;  //Using diretive
or:
        using std::cout; // Using declaration;


but is a good practice not use this, because if you have more than one namespace with the same name inside
this could cause a problem, so try to use always namespace::name like std::cout;


Escape sequence
\n                a new line
\t                a horizontal tab
\r                Carriage return, position the cursor to the current line
\a                Alert, sound the system bell
\\                scape a \ on screen
\'                scape a single quote
\"                scape a double qoute


the return statement in the final the main function is optional


Use identifiers of 31 characters or fewer to ensure portability.


Do not use identifiers that begin with underscores and double underscores, the compiler may use a similar identifier.


Avoid using abbreviations in identifiers. This improves program readability.


some fundamental types: double, bool, int, char


the std::cin, is a standard input stream object cin of namespace std


and the stream extraction operator >> obtain the value inside the variable positioned on the right side of the operator.


Using multiple stream insertion operators (<<) in a single statement is referred to as concatenating, chaining or cascading stream insertion operations.


The stream insertion operator << insert the value on the right’s side of the operator.


the assigment operator “=” on “int number1 = 0;” assign the value 0 to number1.


the “=” and “+” operator is called a binary operator.


Using multiple stream insertion operators (<<) in a single statement is referred to as concatenating, chaining, or cascading stream insertion operations.
when a value is placed in a variable it replaces the previous value, this is called a “destructive” operation.


“nondestructive” operation occurs when the value is read from the memory.




Arithmetic operations:


Operation                       Arithmetic      Algebriac                C++ 
                                Operator        Expression               Expression


Addition                        +                 f + 7                   f + 7
Subtraction                     -                 p – c                   p - c
Multiplication                  *                 bm or b ⋅ m              b * m
Division                        /                 x / y or or x ÷ y        x / y
Modulus                         %                 r mod s                  r % s


The modulus operator “%” only can be used with integers operands. The expression x%y yields
the remainder after x is divided by y.


Precedence of Operators:
1º Parentheses are evaluated first.
2º Multiplication, division, and modulus operations are applied next.
3º Addition and subtraction operations are applied last.


Operator(s) in order of evaluation (precedence)
( )
*
/
%
+
-

Relational Operators:
>
<
>=
<=

Equality Operators:
==
!=

A compound statement or block is when creating one or more statements inside the brackets {...}

some programmers use the directive “using” as in “using namespace std” to use all the names inside std namespace inside of the “iostream” header

Operator Precedence:
()
/ * %
+ -
<< >>
< <= > >=
== !=
=

the  “static_cast<type>(value)” gives us the converted type of value

### 3.1 - Introduction to Classes

### 3.2 Defining a class with a member function

        //in the class name, the first letter of each word is written with a capital letter
        class GradeBook{ // class definition
        public: // here is define a public specifier block, everything that follows bellow is a public member of the class
                // this function member, has a camel case style on its name, the second word has the first letter in capital
                void gradeMessage() const // this line is commonly referred as a function header
                                        // the method follow by the const keyword indicates to compiler 
                                        //that this method doesn't modify the object, like properties for example
                {
                        std::cout << "Grade Message" << std::endl;
                }
        };
        const objects can only call const members

                const GradeBook g;  // the GradeBook here is a user-defined type
                GradeBook.gradeMessage()

        to call a method member of a class is necessary to create an object of it, static members are an exception

### 3.3 Defining a Member Function with a Parameter

        You can define new class types as needed; this is one reason why C++ is known as an "extensible programming language".

        #include <string>
                std::string var;
        std::getline( stream, var); stream is the origin of caracters ex. std::cin, and the var is where to store the whole line 

        we call the method displayMessage(var) passing the course name to the method, copying the value stored in the variable var
        the method displayMessage(std:string nameOfCourse); receives a copied string as a parameter

        ### 3.4 Data Members, set Member Functions and get Member Functions

        variables declared in the class, are called "data members"

        const function member only can call internally const functions member
        set function member is known as mutators because they change the value of a property
        get function member are call as accessors

### 3.5 - Initializating Objects with Contructors
        constructor need to have the same name of the class definition
        make research for explanation about explicit keyword?
        ...
        public:
                explicit GradeBook(std::string name) : courseName(name) {}
        ...
        the : followed by the name of data member with the parameter name inside parentheses to Initialize the data member

### 3.6 Placing a Class in a Separate File for Reusability
        to Reusability of the class is commonly to define the class inside a header file.
        headers can use the using keyword, this why is always use std::

        Additional Software Engineering Issues
            It's a good practice to put a class inside a header file only with the member variable and functions's declaration 
            and the members function definitions put into another cpp file 
            
            ## GradeBook.h
            class GradeBook{
                std::string courseName; 
            public: 
                // the constructor here use a member-initializer list, there is a ":" followed by the class's data-member with the new value for it
                // surrounded by parenthesis
                // this tells to the compiler that only is acceptable to explicit ...
                explicit GradeBook(std::string name);
            
                // bellow is defined all the object’s member functions that will be public
                void setCourseName(std::string name);
                std::string getCourseName() const;
                void displayMessage() const;
            };
            
            ## GradeBook.cpp
            #include <iostream>
            #include <string>
            #include "GradeBook.h"
            
            // bellow is defined all the object’s member functions that will be public
            
            //constructor
            GradeBook::GradeBook(std::string name): courseName(name) {}
            
            //member functions
            void GradeBook::setCourseName(std::string name){
                courseName = name;
            }
            std::string GradeBook::getCourseName() const {
                return courseName;
            }
            void GradeBook::displayMessage() const {
                std::cout << "Welcome to the grade book for " << getCourseName() << "!" << std::endl;
            }
### 4 Control Statements: Part I: Assigment, ++ and -- operators
    Before writing code we must have thorough understanding of the problem, and carefully planned approach to solving it.
    When writing a program, we must also understand the available building blocks and employ proven program construction thechniques.
    
    ## 4.3 Pseudocode
        Pseudocode normally describe only executable statements
        int counter; is not an executable statement
        
        Some programmers choose to list variables and mention their pruposes at the begnning of pseudocode
        
        Example of pseudocode:
            1 Prompt the user to enter the first interger
            2 input the first interger
            3
            4 Prompt the user to enter the second interger
            5 input the second integer
            6
            7 Add first integer and second integer, and store the results
            8 Display result
        
        programs could be written in terms of only three control structures(control statements), namely:
            sequence structure
            selection structure
            repeticion structure
            
        sequence structure is built in C++, the statements are executed in sequence.
        
        UML:
            Active Diagram is an UML resource, and model the Workflow/activity, and include a portion of algorithm, such as the sequence structure
            
            Active Diagram are composed of special-purpose symbols, such as Action State Symbols (a rectangle with its left and right sides replaced with
            arcs curving outward), Diamonds and Small Circles these symbols are connected by Transition Arrows, which represent the flow of the activity
            
            Action States represent the actions to perform and each Action State contains Action Expression, ex. "add grade to total", "add 1 to counter"
            
            The arrow represent Transition
            
            A Solid Circle represent the flow start and the end.
            
            Can be used of UML notes to show a representation in C++ and is connected to the Action State by Dotted Line
            
        Selection Statements
            
            if (single-selection statement), if...else (double-selection statement), switch (multiple-selection statement)
            The if statement is a single-entry/single-exit statement
            
            Forms:
                if(condition)
                    //block of one single line
                
                if(condition){
                    //block of multiple lines
                }
                
                if(condition){
                    //block executed if is true
                } else {
                    //block executed if is condition false    
                }
                
                if(condition){
                    // true block
                } else if (condition){
                    // true block
                } else if (condition) {
                    // true block
                } 
                ...
                else {
                    // block executed if any other options is true
                }
                
                if(condition){
                    ; // as know as null-statement or empty-statement
                }else{
                    // block will executed if condition is false
                }
            ex. of a pseudocode for if statement
            
                if student's grade is greater than or equal to 60
                    print "Passed"
                
                in C++:
                
                    if(grade >= 60)
                        std::cout << "Passed" << std::endl;
                
                If student’s grade is greater than or equal to 60
                    Print “Passed”
                Else
                    Print “Failed”
                
                in C++:
                    if(grade >= 60)
                        std::cout << "Passed" << std::endl;
                    else
                        std::cout << "Failed" << std::endl;
            
            switch will be studied after
        
        Repetition Statements in C++
            
            while, do...while, for
            
            while(condition){
                //block will be executed if the condition is true
            }
            
            do {
                // execute at least once
                // and then if the condition is true
            } while(condition);
            
            for(initiation; condition; incremention/decremention){
                // block is executed if condition is true
            }
            
            ex. of while:
                in pseudocode:
                    while there are more items on my shopping list
                        purchase next item and cross it off my list
                in C++
                    int product = 3;
                    
                    while ( product <= 100 )
                        product = 3 * product
                
        those control statements can be combined in a control-statement stacking or control-statement nesting
        
        C++ Keywords
            Keywords common to the C and C++ programming languages
                auto        break       case        char        const
                continue    default(1)  do          double      else
                enum        extern(1)   float       for         goto
                if          int         long        register(2) return
                short       signed      sizeof(1)   static      struct(1)
                switch      typedef     union       unsigned    void
                volatile    while
            
            C++-only keywords
                and         and_eq          asm         bitand              bitor
                bool        catch           class(1)    compl               const_cast
                delete(1)   dynamic_cast    explicit    export(1)(3)        false
                friend      inline(1)       mutable(1)  namespace           new
                not         not_eq          operator    or                  or_eq
                private     protected       public      reinterpret_cast    static_cast
                template    this            throw       true                try
                typeid      typename        using(1)    virtual             wchar_t
                xor         xor_eq
            
            C++11 keywords
                alignas     alignof     char16_t    char32_t        constexpr
                decltype    noexcept    nullptr     static_assert   thread_local
            
            C++20 keywords
                requires    char8_t     concept     consteval       constinit
                co_await    co_return   co_yield
            
            (1) - meaning changed or new meaning added in C++11.
            (2) - meaning changed in C++17.
            (3) - meaning changed in C++20.
        
        To prevent errors in ours programs is a good practice to validate the input
        
        C++ provide a bool type that hold a true or false value
        
        Conditional operator (?:)
            std::cout << (grade >= 60 ? "Passed" : "Failed") << std::endl;
            
        Nested if…else Statements
            If student’s grade is greater than or equal to 90
                Print “A”
            Else
                If student’s grade is greater than or equal to 80
                    Print “B”
                Else
                    If student’s grade is greater than or equal to 70
                        Print “C”
                    Else
                        If student’s grade is greater than or equal to 60
                            Print “D”
                        Else
                            Print “F”
                            
            if(grade >= 90)
                std::cout << "A" << std::endl;
            else
                if(grade >= 80)
                    std::cout << "B" << std::endl;
                else
                    if(grade >= 70)
                        std::cout << "C" << std::endl;
                    else
                        if(grade >= 60)
                            std::cout << "D" << std::endl;
                        else
                            std::cout << "F" << std::endl;
                            
            if(grade >= 90)
                std::cout << "A" << std::endl;
            else if(grade >= 80)
                std::cout << "B" << std::endl;
            else if(grade >= 70)
                std::cout << "C" << std::endl;
            else if(grade >= 60)
                std::cout << "D" << std::endl;
            else
                std::cout << "F" << std::endl;
        
        An UML's Merge Symbol connects the statement to the condition 
        
        4.8 Formulating Algorithms: counter-controlled repetition
        
            Problem Statement:
                A class of ten students took a quiz. The grades (0 to 100) for this quiz are available to you.
                Calculate and display the total of the grades and the class average
                
                average is equal to the sum of the grades divided by the number of students
                
                a counter-controlled repetition(definite repetition) uses a counter to controle the number of time the block will be executed
            
            Pseudocode for the problem
                
                1 Set total to zero
                2 Set grade counter to one
                3
                4 While grade counter is less than or equal to ten
                5       Prompt the user to enter the next grade
                6       Input the next grade
                7       Add the grade into the total
                8       Add one to the grade counter
                9   
                10 Set the class overage to the total divided by ten
                11 Print the total of the grades for all students in the class
                12 Print the class average
            
            As a recall all the variable should be initialized to avoid errors
            try to resolve all errors and warnings
            
        4.9 Formulating Algorithms: sentinel-controlled repetition
            
            Problem Statement:
                Develop a class average program that processes grades for an arbitrary number of students each time it's run.
            
            a sentinel value is used to stop the while loop, and it is also know as "signal value", a "dummy value" or a "flag value"
            
            Developing the Pseudocode Algorithm with Top-Down, Stepwise Refinement: The Top and First Refinement:
            
            Performing a Top-down, stepwise refinement:
            
                Top: is the hole program description
                    Determine the class average for the quiz for an arbritary number of students
                
                First refinement:
                    (1) Initialize variables
                    (2) Input, sum and count the quiz grades
                    (3) Calculate  and print the total of all student grades and the class average
                    
                Second refinement:
                    (1) Initialize variables
                    
                        its refinement is as follow:
                            Initialize total to zero
                            Initialize counter to zero
                    
                    (2) Input, sum and count the quiz grades
                
                        its refinement is as follow:
                            Prompt the user to enter the first grade
                            Input the first grade (possible the sentinel)
                            
                            While the user has not yet entered the sentiel
                                Add this grade into the running total
                                Add one to the grade counter
                                Prompt the user to enter the next grade
                                Input the next grade (possibly the sentinel)
                        
                    (3) Calculate and print the total of all student grades and the class average
                    
                        its refinement is as follow:
                            If the counter is not equal to zero
                                Set the average to the total divided by the counter
                                Print the total of the grades for all students in the class
                                Print the class average
                            else
                                Print "No grades were entered"
                    
                The complete second refinement
                    Initialize total to zero
                    Initialize counter to zero
                    
                    Prompt the user to enter the first grade
                    Input the first grade (possibly the sentinel)
                    
                    While the user has not yet entered the sentinel
                        Add this grade into the running total
                        Add one to the grade counter
                        Prompt the user to enter the next grade
                        Input the next grade (possibly the sentinel)
                    
                    If the counter is not equal to zero
                        Set the average to the total divided by the counter
                        Print the total of the grades for all students in the class
                        Print the class average
                    else
                        Print "No grades were entered"
                        
                Always prevent possible errors by testing the input before storing in the variables, for example, to avoid division by zero
                
            float is single-precision floating-point numbers, having approximately seven significant digits today
            double is double-precision floating-point numbers, having approximately 15 significant digits today,
            this requires twice as much memory as float variables
            
            floating-point values are known as floating-point literals
            The computer allocates only a fixed amount of space to hold such a value
            
            depend on the program we can use float variable instead of double because we'll not need such precision after the decimal point
            but in a program that needs such precision double is preferred
            
            static_cast<double>(total) is called as explicit conversion
            when we divide an int and double, an implicit convertion of int to double occurs
            
            static_cast is an unary operator cause use only one operator
            
            setprecision is referred as "parameterized stream manipulator"
            setprecision is in <iomanip> header
            
            endl is a nonparameterized stream manipulator, because it isn’t followed by a value or expression in parentheses
            
            The stream manipulator std::fixed indicates that floating-point values should be output in so-called fixed-point format, as opposed to scientific notation.
            Scientific notation for 1.0 and 10.0 multiplied by a power of 10 is show as 1.0x10^1, 3,100.0 = 3.1x10^3
            
            when the std::fixed and std::setprecision are used in a program the printed value is rounded to the number of decimal positions indicated by the value passed to std::setprecision
            in the case setprecision is set to 2 the value 87.946 is output as 87.95 and 67.543 as 67.54

            std::showpoint is a manipulator, and in combination with std::fixed will force the decimal point to appear, both are in <iostream> header
            
        4.10 Formulating Algorithms: Nested Control Statements
            
            Consider the follwing problem statement:
                A college offers a course that prepares students for the state licensing exam for real state
                broker. Last year, ten of the students who completed this course took the exam.
                The college wants to know how well its students did on the exam. You've been asked to
                write a program to summarize the results. You've been given a list of these 10 students.
                Next to each name is written a 1 if the student passed the exam or a 2 if the student failed.
                
            Your program should analyze the results of the exam as follows:
                1. Input each test result (i.e., a 1 or a 2). Display the prompting message "Enter result" each
                   time the program requests another test result.
                2. Count the number of test results of each type.
                3. Display a summary of the test results indicating the number of students who passed and the number who failed
                4. If more than eitht students passed the exam, print the message "Bonus to instructor!"
                
            After reading the problem statement carefully, we make the following observations:
            	1. The program must process test results for 10 students. A counter-controlled loop
            	   can be used because the number of test results is known in advance
            	2. Each test result is a number - either a 1 or a 2. Each time the program reads a test
            	   result, the program must determine whether the number is a 1 or a 2. For simplicity, 
            	   we test only for a 1 in our algorithm. If the number is not a 1, we assume that it's a 2
            	   (Please be sure to do Exercise 4.20, which considers the consequences of this assumption.)
            	3. Two counters are used to keep track of the exam results - one to count the number of students
            	   who passed the exam and one to count the number of students who failed the exam.
            	4. After the program has processed all the results, it must decide whether more than eight students
            	   passed the exam.
            
            Stepwise refinement
                    Analyze exam results and decide whether a bonus should be paid
                
                become
                
                    (1) Initialize variables
                    (2) Input the 10 exam results, and count passes and failures
                    (3) Display a summary of the exam results and decide whether a bonus should be paid
                
                refining even more
                
                    (1) Initialize variables
                        Initialize passes to zero
                        Initialize failures to zero
                        Initialize student counter to one
                        
                    (2) Input the 10 exam results, and count passes and failures
                        While student counter is less than or equal to 10
                        	Prompt the user to enter the next exam result
                        	Input the next exam result
                        	
                        	If the student passed
                        		Add one to passes
                        	Else
                        		Add one to failures
                        	
                        	Add one to student counter
                        	
                    (3) Display a summary of the exam results and decide whether a bonus should be paid
                        Display the number of passes
                        Display the number of failures
                        
                        If more than eight students passed
                        	Display "Bonus to instructor!"
                
                a complete pseudocode:
                    Initialize passes to zero
                        1   Initialize failures to zero
                        2   Initialize student counter to one
                        3 
                        4   While student counter is less than or equal to 10
                        5       Prompt the user to enter the next exam result
                        6	    Input the next exam result
                        7	
                        8	    If the student passed
                        9		    Add one to passes
                        10	    Else
                        11		    Add one to failures
                        12	
                        13	    Add one to student counter
                        14	
                        15  Display the number of passes
                        16  Display the number of failures
                        17
                        18  If more than eight students passed
                        19      Display "Bonus to instructor!"
            C++11 List Initialization
            	Normal way
            		unsigned int studentCounter = 1;
            	C++11
            		unsigned int studentCounter = {1};
            		
            	    or
            	        
            		unsigned int studentCounter{1};
            		
            	list-initialization syntax also prevents so-called "narrowing conversions" that could result in data loss
            	    int a = 1.77 // a = 1 give us a warning but will compile but later can cause some logic error
            	    int a = {1.77} or int a{1.77} // will give us an error and will not compile
            	
            	for classes with explicit constructors that initilize all variable members, 
                there are only two ways to initilize an object
            	    
            	    ClassName cls1(value1, value2, ...);
            	    
            	    or
            	    
            	    ClassName cls1{value1, value2,...};
            	    
            	    but
            	    
            	    ClassName cls1 = {value1, value2,...}; // will cause an compilation error
        
        4.11 Assignment Operators
            c = c + 3;   =>   c += 3;
            
            some operators
                +  =>  +=
                -  =>  -=
                *  =>  *=
                /  =>  /=
                %  =>  %=
            
            variable = varibalbe operator variable;
            variable += variable;
            
        4.12 Increment and Decrement Operators
            unary incremet operator ++
            unary decrement operator --
            
            ++a     Increment by 1, then use the new value of a in the expression in which a resides
            a++     Use the current value of a in the expression which a resides, then increment a by 1
            --a     Decrement by 1, then use the new value of a in the expression in which a resides
            a--     Use the current value of a in the expression which a resides, then decrement a by 1
            
            Preincrement or Predecrement ++a or --a, --a => --/++ is prefixed
            Postincrement or Postdecrement a++ or a--,  a-- => --/++ is postfixed
            
            unsing pre or post increment and decrement operators in the statement have the same logic effect
            but in expressions, we should be careful because can cause different results
            use increment and decrement with modifiable variables
            
            Operators                   Associativity   Type
            :: ()                       left to right   primary
                            [See caution in Fig. 2.10 regarding grouping parentheses.]
            
            ++ -- static_cast<type>()   left to right   postfix
            ++ -- + -                   right to left   unary (prefix)
            * / %                       left to right   multiplicative
            + -                         left to right   additive
            << >>                       left to right   insertion/extraction
            < <= > >=                   left to right   relational
            == !=                       left to right   equality
            ?:                          right to left   conditional
            = += -= *= /= %=            right to left   assignment
            
    Exercises (answers):
        4.1
            a) All programs can be written in terms of three types of control structures: "Sequence", "selection" and "repetition".
            b) The "if...else" selection statement is used to execute one action when a condition is true
            or a different action when that condition is false.
            c) Repeating a set of instructions a specific number of times is called "counter-controlled or definitive" repetition.
            d) When it isn’t known in advance how many times a set of statements will be repeated,
            a(n) "Sentinel, signal, flag or dummy" value can be used to terminate the repetition.
        4.2
        	x = x + 1;
        	x += 1;
        	++x;
        	x++;
        4.3
        	a) z = x++ + y;
        	b) if ( count > 10 )
        		std::cout << "Count is greater than 10." std::endl;
        	c) total -= --x
        	d) q %= divisor
        	   q = q % divisor
        4.4
        	a) unsigned int sum = 0
        	b) unsigned int x = 1
        	c) sum += x
        	d) std::cout << "The sum is: " << sum << std::endl;
        4.5
        	#include <iostream>
        	int main()
        	{
        		unsigned int sum = 0;
        		unsigned int x = 1;
        
        		while( x < 11 ){
        			sum += x++;
        		}
        	    std::cout << "The sum is: " << sum << std::endl;
        	}
        4.6
            a) product *= x++; product = 25, x = 6
            b) quotient /= ++x; quocient = 0, x = 6 // here was considered x = 5 again
        4.7
            a) Input unsigned int variable x with cin and >>.
            	std::cin >> x;
            b) Input unsigned int variable y with cin and >>.
            	std::cin >> y;
            c) Declare unsigned int variable i and initialize it to 1.
            	unsigned int i = 1;
            d) Declare unsigned int variable power and initialize it to 1.
            	unsigned int power = 1;
            e) Multiply variable power by x and assign the result to power.
            	power *= x;
            f) Preincrement variable i by 1.
            	++i;
            g) Determine whether i is less than or equal to y.
            	if( i <= y )
            h) Output integer variable power with cout and <<.
            	std::cout << power << std::endl;
        4.8 
            unsigned int x;
            unsigned int y;
            unsigned int i = 1;
            unsigned int power = 1;
            
            std::cout << "Enter base as an integer: ";
        	std::cin >> x;
        	std::cout << "Enter exponent as an integer: ";
        	std::cin >> y;
        	
        	while(i <= y)
        	{
            	power *= x;
            	++i;
            }
        	std::cout << power << std::endl;
        4.9 
            a) while ( c <= 5 )
               {
                    product *= c;
                    ++c;
               }// was missing
            b)  cin << value; //correct answer: should use >> in std::cin
            c)  if ( gender == 1 )
                    cout << "Woman" << endl;
                else //; should not be placed here
                    cout << "Man" << endl;
        4.10
            int z = 0;
            int sum = 0;
            while ( z >= 0 ) // infinity loop if z is >= 0; z should be decremented
                sum += z;
                
        4.11 (Correct the Code Errors) Identify and correct the error(s) in each of the following:
                a)  if ( age >= 65 ) //; should not be placed here otherwise will cause an error
                        cout << "Age is greater than or equal to 65" << endl;
                    else
                        cout << "Age is less than 65 << endl";
                b)  if ( age >= 65 )
                        cout << "Age is greater than or equal to 65" << endl;
                    else //;should not be placed here otherwise will cause an error
                        cout << "Age is less than 65 << endl";
                c)  unsigned int x = 1;
                    unsigned int total;// was not initialized
                    while ( x <= 10 )
                    {
                        total += x;
                        ++x;
                    }
                d)  While ( x <= 100 )
                        total += x;
                        ++x;
                    //curly braces are missing
                e)  while ( y > 0 )
                    {
                        cout << y << endl;
                        ++y;
                    }
                    //infinity loop, y should be decremented
        4.12 (What Does this Program Do?) What does the following program print?
            #include <iostream>
            
            int main(){
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
            
            Prints the double of each number from 1 to 10, summing their total and showing the result
            
        For Exercises 4.13–4.16, perform each of these steps:
            a) Read the problem statement.
            b) Formulate the algorithm using pseudocode and top-down, stepwise refinement.
            c) Write a C++ program.
            d) Test, debug and execute the C++ program.
        
        4.13 
        // implement the exercises here
                
### 5 for Repetition Statement
    off-by-one errors occur when we use wrongly < instead <= for example when we want to count from 1 to 10, and showing only 1 to 9
        for(unsigned int i = 1; i < 10; i++)
            std::cout << i << " ";

    for ( initialization; loopContinuationCondition; increment )
        statement

    initialization;
    while ( loopContinuationCondition )
    {
        statement
        increment;
    }

    different ways to increment:
        counter = counter + 1
        counter += 1
        ++counter
        counter++
    
    loop for can contain arithmetic expressions
        unsigned int x = 2;
        unsigned int y = 10;

        for ( unsigned int j = x; j <= 4 * x * y; j += y / x )

        or can be expressed this way

        for ( unsigned int j = 2; j <= 80; j += 5 )

    to count downward should use decrement operator --x, x--

    avoid change the vairable used in for loop from the for body.

    Variety of for-loop uses
        a) Vary the control variable from 1 to 100 in increments of 1.
        
            for ( unsigned int i = 1; i <= 100; ++i )
        
        b) Vary the control variable from 100 down to 0 in decrements of 1. Notice that we
           used type int for the control variable in this for header. The condition does not
           become false until control variable i contains -1, so the control variable must be
           able to store both positive and negative numbers.
            
            for ( int i = 100; i >= 0; --i )
        
        c) Vary the control variable from 7 to 77 in steps of 7.
            
            for ( unsigned int i = 7; i <= 77; i += 7 )

        d) Vary the control variable from 20 down to 2 in steps of -2.

            for ( unsigned int i = 20; i >= 2; i -= 2 )
        
        e) Vary the control variable over the following sequence of values: 2, 5, 8, 11, 14, 17.

            for ( unsigned int i = 2; i <= 17; i += 3 )

        f) Vary the control variable over the following sequence of values: 99, 88, 77, 66, 55.

            for ( unsigned int i = 99; i >= 55; i -= 11 )
        
    Do not use != or == in test in a for loop because if the for loop in the increment phase steps by 2
    can cause logic error and infinit loop
    
    Application: Compound Interest Calculations
        A person invests $1000.00 in a savings account yielding 5 percent interest. Assuming
        that all interest is left on deposit in the account, calculate and print the amount of
        money in the account at the end of each year for 10 years. Use the following formula
        for determining these amounts:
        a = p ( 1 + r )n
        where
            p is the original amount invested (i.e., the principal),
            r is the annual interest rate,
            n is the number of years and
            a is the amount on deposit at the end of the nth year.
    
    #include <iomanip>
        std::setw(4) // will set 4 spaces to the field
        std::cout << std::setw(4) << year << std::setw(21) << amount << std::endl;
            1             1050.00
    #include <iostream>
        is possible to use left and right to positioned values on fields
        std::left
        std::right
        
    #include <cmath>
        std::pow(base, exponent)
    
    Logical Operators
        >       a > b
        <       a < b
        >=      a >= b
        <=      a <= b
        ==      a == b  -a is equal b
        !=      a != b  -a is not equal to b
        &&      gender == FEMALE && age >= 65
        ||      gender == FEMALE || age >= 65
        !       !b - if be is false evalute to true, or true to false
    Precedence of operators
        Operators                       Associativity               Type
        :: ()                           left to right               primary
        ++ -- static_cast< type >()     left to right               postfix
        ++ -- + - !                     right to left               unary (prefix)
        * / %                           left to right               multiplicative
        + -                             left to right               additive
        << >>                           left to right               insertion/extraction
        < <= > >=                       left to right               relational
        == !=                           left to right               equality
        &&                              left to right               logical AND
        ||                              left to right               logical OR
        ?:                              right to left               conditional
        = += -= *= /= %=                right to left               assignment
        ,                               left to right               comma
    
    Structured programming result in three froms of control:
        Sequence    - line by line
        Selection   - if, if..else, switch
        Repetition  - do..while, for, while
    
    Exercises:
        5.1 State whether the following are true or false. If the answer is false, explain why.
            a) The default case is required in the switch selection statement.
                False The default case is optional. Nevertheless, it’s considered good software engineering
                to always provide a default case.
            b) The break statement is required in the default case of a switch selection statement to
            exit the switch properly.
                True
            c) The expression ( x > y && a < b ) is true if either the expression x > y is true or the
            expression a < b is true.
                False the && operator sets that left and right tests should be true to evaluate true
            d) An expression containing the || operator is true if either or both of its operands are
            true.
                True
        5.2 Write a C++ statement or a set of C++ statements to accomplish each of the following:
            a) Sum the odd integers between 1 and 99 using a for statement. Use the unsigned int
            variables sum and count.

            b) Print the value 333.546372 in a 15-character field with precisions of 1, 2 and 3. Print
            each number on the same line. Left-justify each number in its field. What three values
            print?
            c) Calculate the value of 2.5 raised to the power 3 using function pow. Print the result with
            a precision of 2 in a field width of 10 positions. What prints?
                std::cout << std::fixed << std::setprecision(2);
                std::cout << std::setw(10) << std::pow(2.5,3)
            d) Print the integers from 1 to 20 using a while loop and the unsigned int counter variable
            x. Print only 5 integers per line. [Hint: When x % 5 is 0, print a newline character; otherwise,
            print a tab character.]
            e) Repeat Exercise 5.2(d) using a for statement.

### 6 Functions and an Introduction to Recursion
    To promote software reusability, every function should be limited to performing a single,
        well-defined task, and the name of the function should express that task effectively.
    <cmath> header

        Function        Description                             Example
        ceil( x )       rounds x to the smallest integer        ceil( 9.2 ) is 10.0
                        not less than x                         ceil( -9.8 ) is -9.0
        cos( x )        trigonometric cosine of x               cos( 0.0 ) is 1.0
                        (x in radians)
        exp( x )        exponential function ex                 exp( 1.0 ) is 2.718282
                                                                exp( 2.0 ) is 7.389056
        fabs( x )       absolute value of x                     fabs( 5.1 ) is 5.1  
                                                                fabs( 0.0 ) is 0.0
                                                                fabs( -8.76 ) is 8.76
        floor( x )      rounds x to the largest integer         floor( 9.2 ) is 9.0
                        not greater than x                      floor( -9.8 ) is -10.0
        fmod( x, y )    remainder of x/y as a floatingpoint     fmod( 2.6, 1.2 ) is 0.2
                        number
        log( x )        natural logarithm of x (base e)         log( 2.718282 ) is 1.0
                                                                log( 7.389056 ) is 2.0
        log10( x )      logarithm of x (base 10)                log10( 10.0 ) is 1.0
                                                                log10( 100.0 ) is 2.0
        pow( x, y )     x raised to power y (xy)                pow( 2, 7 ) is 128
                                                                pow( 9, .5 ) is 3
        sin( x )        trigonometric sine of x                 sin( 0.0 ) is 0
                        (x in radians)
        sqrt( x )       square root of x (where x is a          sqrt( 9.0 ) is 3.0
                        nonnegative value)
        tan( x )        trigonometric tangent of x              tan( 0.0 ) is 0
                        (x in radians)
        
    Argument Coercion
        forcing arguments to the appropriate types specified by the parameter declarations.
        ex.: function prototype with a dobule as argument and when it is called with a integer passed as paramenter
        the function will still works.
    
    Argument Promotion Rules and Implicit Conversions(1)
        
        Data types

        long double
        double
        float
        unsigned long long int      (synonymous with unsigned long long)
        long long int               (synonymous with long long)
        unsigned long int           (synonymous with unsigned long)
        long int                    (synonymous with long)
        unsigned int                (synonymous with unsigned)
        int
        unsigned short int          (synonymous with unsigned short)
        short int                   (synonymous with short)
        unsigned char
        char and signed char
        bool

        Standard Library header                                  Explanation
            <iostream>                          Contains function prototypes for the C++ standard input and output
                                                functions, introduced in Chapter 2, and is covered in more detail in
                                                Chapter 13, Stream Input/Output: A Deeper Look.
           
            <iomanip>                           Contains function prototypes for stream manipulators that format
                                                streams of data. This header is first used in Section 4.9 and is discussed
                                                in more detail in Chapter 13, Stream Input/Output: A Deeper Look.
            
            <cmath>                             Contains function prototypes for math library functions (Section 6.3).
            
            <cstdlib>                           Contains function prototypes for conversions of numbers to text, text
                                                to numbers, memory allocation, random numbers and various other
                                                utility functions. Portions of the header are covered in Section 6.7;
                                                Chapter 11, Operator Overloading; Class string; Chapter 17, Exception
                                                Handling: A Deeper Look; Chapter 22, Bits, Characters, C Strings
                                                and structs; and Appendix F, C Legacy Code Topics.
            
            <ctime>                             Contains function prototypes and types for manipulating the time and
                                                date. This header is used in Section 6.7.
            
            <array>,                            These headers contain classes that implement the C++ Standard Library
            <vector>, <list>,                   containers. Containers store data during a program’s execution. The
            <forward_list>,                     <vector> header is first introduced in Chapter 7, Class Templates array
            <deque>, <queue>,                   and vector; Catching Exceptions. We discuss all these headers in
            <stack>, <map>,                     Chapter 15, Standard Library Containers and Iterators.
            <unordered_map>,
            <unordered_set>,
            <set>, <bitset>                     
            
            <cctype>                            Contains function prototypes for functions that test characters for certain
                                                properties (such as whether the character is a digit or a punctuation),
                                                and function prototypes for functions that can be used to convert
                                                lowercase letters to uppercase letters and vice versa. These topics are discussed
                                                in Chapter 22, Bits, Characters, C Strings and structs.
            
            <cstring>                           Contains function prototypes for C-style string-processing functions.
                                                This header is used in Chapter 10, Operator Overloading; Class
                                                string.
            
            <typeinfo>                          Contains classes for runtime type identification (determining data types
                                                at execution time). This header is discussed in Section 12.8.
            
            <exception>,                        These headers contain classes that are used for exception handling (discussed
            <stdexcept>                         in Chapter 17, Exception Handling: A Deeper Look).
            
            <memory>                            Contains classes and functions used by the C++ Standard Library to
                                                allocate memory to the C++ Standard Library containers. This header is
                                                used in Chapter 17, Exception Handling: A Deeper Look.
            
            <fstream>                           Contains function prototypes for functions that perform input from
                                                and output to files on disk (discussed in Chapter 14, File Processing).
            
            <string>                            Contains the definition of class string from the C++ Standard Library
                                                (discussed in Chapter 21, Class string and String Stream Processing).
            
            <sstream>                           Contains function prototypes for functions that perform input from
                                                strings in memory and output to strings in memory (discussed in
                                                Chapter 21, Class string and String Stream Processing).
            
            <functional>                        Contains classes and functions used by C++ Standard Library algorithms.
                                                This header is used in Chapter 15.
            
            <iterator>                          Contains classes for accessing data in the C++ Standard Library containers.
                                                This header is used in Chapter 15.
            
            <algorithm>                         Contains functions for manipulating data in C++ Standard Library containers.
                                                This header is used in Chapter 15.
            
            <cassert>                           Contains macros for adding diagnostics that aid program debugging.
                                                This header is used in Appendix E, Preprocessor.
            
            <cfloat>                            Contains the floating-point size limits of the system.
            
            <climits>                           Contains the integral size limits of the system.
            
            <cstdio>                            Contains function prototypes for the C-style standard input/output
                                                library functions.
            
            <locale>                            Contains classes and functions normally used by stream processing to
                                                process data in the natural form for different languages (e.g., monetary
                                                formats, sorting strings, character presentation, etc.).
            
            <limits>                            Contains classes for defining the numerical data type limits on each
                                                computer platform.
            
            <utility>                           Contains classes and functions that are used by many C++ Standard
                                                Library headers.

            std::srand(unsigned int)                seeds the rand() function

            #include <ctime>
                time(); 

            enum Type-name { VALUES, ....} 
            enum class Type-name { VALUES, ...}
            enum struct Type-name { VALUES, ...}
            enum class Type-name: type { VALUES, ...} type could be unsigned int, short int, long long, etc...
            enum struct Type-name: type { VALUES, ...} type could be unsigned int, short int, long long, etc...

            #include <random> // c++11
            // like srand(), Its constructor argument seeds the random-number generation engine with the current time.
            // If you don’t pass a value to the constructor, the default seed will be used and the program will produce
            // the same sequence of numbers each time it executes.
            std::default_random_engine engine( static_cast<uint32_t>( time( 0 ) ) ); 

            // randomInt creates an unsigned int number
            std::uniform_int_distribution<uint32_t> randomInt(1, 6); // set min and max range of values

            // send to randomInt the engine to seed the random number generator, getting back the random number.
            and randomInt( engine ); set the seed end return the random number
        
        6.10 Storage Classes and Storage Duration

            The attributes of variables include name, type, size and value. Each identifier in a program also has other attributes,
            including "storage duration", scope and "linkage"

            C++ provides five "storage-class specifiers" that determine a variable’s storage duration:
            "register", "extern", "mutable" and "static".

            "mutable" is used exclusively with classes
            "thread_local" is used with multithread applications

            Storage Duration
                An identifier’s storage duration determines the period during which that identifier exists in memory.
                Some exist briefly, some are repeatedly created and destroyed and others exist for a program’s entire execution
                An identifier’s storage-class specifier helps determine its storage duration and linkage.
                Four storage durations: automatic, static, dynamic and thread

                Some storage durations "static" and "automatic"
            Scope
                An identifier's scope is where the identifier can be referenced in a program. 
                        - Throughout a program
                        - A limited portion of a program
            Linkage
                An identifier's linkage determine if the declaration is known in the source file or across multiple files and then
                the linker put them together.
            
            Local Variables and Automatic Storage Duration
                - Local variables declare in functions
                - function parameters
                - local variables or function parameters declared with register
                
                Local variables has automatic storage duration, also call as automatic variables
            
            Register Variables:
                The compiler might ignore register declarations. For example, there might not be a
                sufficient number of registers available.

                    register unsigned int counter = 1;

                The definition suggests that the unsigned int variable counter be placed in one of the computer’s registers; 
                regardless of whether the compiler does this, counter is initialized to 1:

                The register keyword can be used only with local variables and function parameters.
                Often, register is unnecessary. Today’s optimizing compilers can recognize frequently
                used variables and may place them in registers without needing a register declaration.

            Static Storage Duration
                Keywords "extern" and "static" declare identifiers for variables with static storage duration and for functions
                Variables with static storage duration exist int memory from the point at which the program begins execution and
                util the program terminates
            
            Identifiers with Static Storage Duration
                there are two types of identifiers:
                    - external identifiers ( such as global variables )
                    - local variables
                both declared with storage-class identifier static

                avoid use global variables because that could cause problemas if some function change the value of it
                variables should be declare inside of a function stead global

            static Local Variables
                
                static unsigned int count = 1;

                static variables retain their value even when the function ends e return to the caller if the function is 
                called again the static variable still have the last value from when the function was called.
                it's a good practice initilized all the variables
                storage-class specifiers
                    extern
                    static
                They have special meaning when they're applied explicity to external identifiers such as global variables and global
                function names

            Scope Rules
                block scope  
                        variables declared inside {...} in a function and function parameter,
                        are accessed inside a nested block inside the function
                        static variables have block scope, exist since program begins
                function scope
                        - start:
                        - case in switch statement
                global namespace scope
                        Global variables, function definitions and function prototypes placed outside a function all have 
                        global namespace scope.
                function-prototype scope
                        identifiers used in function parameters in a function-prototype, those no necessary need a name for the prameters
                        only on function's definition.
                class scope
                namespace scope

        6.14 Inline Functions
            Inline function the compiler put the body content on the place the function is being called

                inline double cube( const double );

        6.15 References and Reference Parameters
            A reference parameter is an alias for its corresponding argument in a function call
                
                int& cube

        6.16 Default Arguments
            Default values are set in the prototype or when the definition is the prototype, but if is provided a prototype
            the default values are declared in the prototype, and the definition look like this without default values:
                
                // Prototype declaration
                unsigned int boxVolume( unsigned int length = 1, unsigned int width = 1, unsigned int height = 1 );
                
                // Definition
                unsigned int boxVolume( unsigned int length, unsigned int width, unsigned int height ){
                    return length * width * height;
                }

        6.17 Unary Scope Resolution Operator (::)
            int a = 12;
            int main(){
                int a = 22;
                std::cout << ::a << " " << a << std::endl;
            }
            > 12 22

        6.18 Function Overloading
            function overloading happens when functions have the same name but have different signatures
        
        6.19 Function Templates
            template < typename T >
            T functionName( T value ){
                retrun value * value
            }
        
            C++11—Trailing Return Types for Functions (->)
               template < typename T >
                auto maximum( T x, T y, T z ) -> T
        
        6.20 Recursion
            it's a function that calls itself
        
            unsigned long int               - 4 bytes (32 bits) - 0 -> 4,294,967,295
            long int                        - 4 bytes (32 bits) - –2,147,483,647 -> 2,147,483,647
            unsigned long long int (C++11)  - 8 bytes (64 bits) - 0 -> 18,446,744,073,709,551,615
        
        6.21 Example Using Recursion: Fibonacci Series
            The Fibonacci series
                0, 1, 1, 2, 3, 5, 8, 13, 21, …
            
            Recursive Fibonacci Definition
                fibonacci(0) = 0
                fibonacci(1) = 1
                fibonacci(n) = fibonacci(n – 1) + fibonacci(n – 2)

            Performace Tip:
                Avoid Fibonacci-style recursive programs that result in an exponential “explosion” of calls.
        
        6.22 Recursion vs. Iteration
            Any problem that can be solved recursively can also be solved iteratively

            Performance Tip 6.9
                Avoid using recursion in performance situations. Recursive calls take time and consume additional memory.
    
    Exercícios:
        page 263.

### 7 Class Templates array and vector; Catching Exceptions

        Operators                               Associativity                               Type
        :: ()                                   left to right                               primary
                                                [See caution in Fig. 2.10 regarding
                                                grouping parentheses.]
        () [] ++ -- static_cast<type>(operand)  left to right                               postfix
        ++ -- + - !                             right to left                               unary (prefix)
        * / %                                   left to right                               multiplicative
        + -                                     left to right                               additive
        << >>                                   left to right                               insertion/extraction
        < <= > >=                               left to right                               relational
        == !=                                   left to right                               equality
        &&                                      left to right                               logical AND
        ||                                      left to right                               logical OR
        ?:                                      right to left                               conditional
        = += -= *= /= %=                        right to left                               assignment
        ,                                       left to right                               comma

        7.3 Declaring arrays
            std::array< type, arraySize > arrayName;

            std::array< int, 12 > c; // declare but not initialize it
            std::array< int, 5 > c = {1,2,3,4,5};
            std::array< int, 5 > c = {}; // initialize to 0

            const size_t mysize = 5; // always initialize a constant variable
            std::array< int, mysize > c = {};
            
            c.size(); // return the size of array

            // another way to declare and initiate an array
            int c[5]{1,2,3,4,5};

            // only declare to be filled in another time
            int c[5];

        7.5 Range-Based for Statement
            for ( rangeVariableDeclaration : expression )
                statement

            std::array< int, 5 > items = { 1,2,3,4,5 };
            for (int item : items) {
                std::cout << item << " ";
            }

            for (int& itemRef : items) {
                itemRef *= 2;
            }

        7.10 Introduction to C++ Standard Library Class Template vector
            
*/