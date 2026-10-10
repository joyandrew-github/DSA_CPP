
// Combination of inheritance types
// Hybrid inheritance is a combination of two or more inheritance types.
// #include <iostream>
// using namespace std;

// class Person
// {
// public:
//     string name;
//     Person(string n) : name(n) {}
// };

// class Employee : public Person
// {
// public:
//     Employee(string n) : Person(n) {}
// };

// class Student : public Person
// {
// public:
//     Student(string n) : Person(n) {}
// };

// class WorkingStudent : public Employee, public Student
// {
// public:
//     WorkingStudent(string n) : Employee(n), Student(n) {}
// };
// int main()
// {
//     WorkingStudent ws("Joy");
//     // cout << ws.Employee::name << endl; // Accessing name from Employee
//     // cout << ws.Student::name << endl;  // Accessing name from Student
//     // cout << ws.name << endl;  //ambiguous
//         // Accessing name from WorkingStudent
//     return 0;
// }





#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;

    Person(string n) : name(n) {}
};

class Employee : virtual public Person {
public:
    int employeeId;

    Employee(string n, int id)
        : Person(n), employeeId(id) {}
};

class Student : virtual public Person {
public:
    string college;

    Student(string n, string c)
        : Person(n), college(c) {}
};

class WorkingStudent : public Employee, public Student {
public:
    WorkingStudent(string n, int id, string c)
        : Person(n),
          Employee(n, id),
          Student(n, c) {}
};

int main() {
    WorkingStudent ws("Joy", 101, "SECE");

    cout << "Name: " << ws.name << endl;
    cout << "Employee ID: " << ws.employeeId << endl;
    cout << "College: " << ws.college << endl;

    return 0;
}