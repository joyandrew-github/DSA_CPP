#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() {
        cout << "This is Base class\n";
    }
};

class Derived : public Base {
public:
    virtual void show() {
        cout << "This is Derived class\n";
    }
};

int main() {
    Base* b;
    Derived d;
    b = &d;

    b->show();
    b->Base::show();
    // b->Derived::show();  
}