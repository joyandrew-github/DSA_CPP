// Constructor overloading means defining multiple constructors in the same class with different parameter lists.
#include <iostream>
using namespace std;

class Vehicle {
public:
    string name;
    int price;

    Vehicle(string n) : name(n), price(0) {}

    Vehicle(string n, int p) : name(n), price(p) {}

    void display() {
        cout << name << " - " << price << endl;
    }
};

int main() {
    Vehicle v1("BMW");
    Vehicle v2("Audi", 5000000);

    v1.display();
    v2.display();
}