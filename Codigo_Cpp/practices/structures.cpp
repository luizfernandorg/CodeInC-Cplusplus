#include <iostream>
struct teste {
    int x;
    int y;
    teste(){
        x = 1;
        y = 1;
        std::cout << "This is the contructor\n";
    }
    //This is a method, will be executed by call as teste(1,2);
    teste(int a, int b){
        x = a;
        y = x * b;

        std::cout << x << y << "\n";
    }
};
struct rect
{
    float a; //for height
    int b; //for width
    rect()
    {
        a=10.58;
        b=4;
        std::cout << "Area at default constructor is: " << a*b << "\n";
    }
    rect( float x, int y)
    {
        std::cout << "Area is: " << x*y;
    }
};
int main()
{
    rect r1;
    teste t; // automaticly call teste();
    teste(5,10);
  
    float x;
    int y;
    
    std::cout << "Enter height value: \n";
    std::cin >> x;
    std::cout << "Enter width value: \n";
    std::cin >> y;
    rect(x,y);
}