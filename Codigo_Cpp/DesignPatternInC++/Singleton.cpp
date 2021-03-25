#include <iostream>

class Singleton{
    public:
        static Singleton &get(){
            static Singleton* sing = new Singleton;
            return *sing;
        }

        void Hello(){
            std::cout << "I'm Hello World in Singleton\n";
        }
};

int main(){
    Singleton::get().Hello();
    std::cin.get();   
}