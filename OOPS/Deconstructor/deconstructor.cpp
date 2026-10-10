// A destructor is a special member function of a class that is automatically called when an object is destroyed.
// It is mainly used to release resources such as dynamically allocated memory, files, and other resources owned by an object.

#include <iostream>
using namespace std;

class Student {
public:
    Student() {
        cout << "Constructor called" << endl;
    }

    ~Student() {
        cout << "Destructor called" << endl;
    }
};

int main() {
    Student s1;

    cout << "Inside main()" << endl;

    return 0;
}