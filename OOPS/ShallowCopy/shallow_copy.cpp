// Shallow Copy in C++ 
// Shallow copy means copying the values of an object's data members into another object. If a data member is a pointer, only the pointer address is copied, not the dynamically allocated memory itself.

#include <iostream>
using namespace std;

class Student {
public:
    int* marks;

    // Student(int m) {
    //     marks = new int(m);
    // }
    Student(int marks):marks(new int(marks)) {} 
};

int main() {
    Student s1(90);

    Student s2 = s1;  // Shallow copy

    cout << *s1.marks << endl;  // 90
    cout << *s2.marks << endl;  // 90

    *s2.marks = 50;

    cout << *s1.marks << endl;  // 50
    cout << *s2.marks << endl;  // 50

    return 0;
}