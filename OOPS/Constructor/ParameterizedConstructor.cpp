//A parameterized constructor accepts values when creating an object
#include <iostream>
using namespace std;

class Employee {
public:
    int id;
    string name;

    Employee(int i, string n) {
        id = i;
        name = n;
    }

    void display() {
        cout << id << " " << name << endl;
    }
};

int main() {
    Employee e1(101, "Joy");
    Employee e2(102, "Andrew");

    e1.display();
    e2.display();

    return 0;
}