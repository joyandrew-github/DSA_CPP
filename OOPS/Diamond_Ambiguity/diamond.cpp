// Diamond Ambiguity in C++ 💎
// Diamond ambiguity is a problem that occurs in multiple inheritance when a class inherits the same base class through two different intermediate classes

#include <iostream>
using namespace std;

class Person {
public:
    int age=20;
};

class Student : virtual public Person {
public:
    void displayAge() {
        cout << "Student Age: " << age << endl;
    }
};

class Employee : virtual public Person {
public: 
    void displayAge() {
        cout << "Employee Age: " << age << endl;
    }
};

class TeachingAssistant : public Student, public Employee {
public:
    void displayAge() {
        // Ambiguity arises here because both Student and Employee have a member named 'age'
        cout << "Teaching Assistant Age: " << age << endl; // Resolving ambiguity using scope resolution
    }
};

int main(){
    TeachingAssistant ta;
    ta.displayAge();
     cout << "Student Age: "
         << ta.Student::age << endl;

    cout << "Employee Age: "
         << ta.Employee::age << endl;
    return 0;
}



// What is diamond ambiguity in C++ and how can you resolve it?
// A strong answer:
// Diamond ambiguity occurs in multiple inheritance when a class inherits the same base class through two different intermediate classes. This can cause duplicate base-class subobjects and ambiguity when accessing inherited members. We can resolve it using virtual inheritance, which ensures that the most-derived class shares a single base-class subobject.

// Remember this for placements:
// - Multiple inheritance creates the diamond structure.
// - Duplicate base-class subobjects cause the ambiguity.
// - virtual public BaseClass is the standard solution.




//if we remove virtual keyword from Student and Employee class then we will get the following error:
// error: request for member 'age' is ambiguous
