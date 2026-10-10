// 4. Abstraction using abstract classes
// This is a particularly important topic for C++ placement interviews.
// An abstract class is a class that cannot be instantiated directly and contains at least one pure virtual function.





// What is a pure virtual function?
// A pure virtual function is declared by assigning = 0 to a virtual function.
//Syntax:
// virtual void functionName() = 0;
#include <iostream>
using namespace std;

class Shape{
    public:
        virtual void draw()=0;

};

class Circle: public Shape{
    public:
        void draw() override{
            cout<<"Drawing an circle"<<endl;
        }
};

class Rectangle : public Shape{
    public:
        void draw() override{
            cout<<"Drawing an rect";
        }
};


int main(){
    Circle c;
    Rectangle r;
    c.draw();
    r.draw();
    return 0;
}