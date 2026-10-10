//One parent → one child

#include <iostream>
#include <string>
using namespace std;

class Base {
public:
    string name;

    // Base(string name) : name(name) {
    // }
    Base(string n){
        name=n;
    }

    void displayName() {
        cout << "Name: " << name << endl;
    }
};

class Derived : public Base {
public:
    // Derived(string name) : Base(name) {
    // }
    Derived(string n):Base(n){
        name=n;
    }

    void displayRole() {
        cout << "Role: Software Developer" << endl;
    }
};

int main() {
    Derived obj("Joy");

    obj.displayName();  // Inherited from Base
    obj.displayRole();  // Defined in Derived

    return 0;
}