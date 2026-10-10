// 1. What is Deep Copy?
// Deep copy means creating a completely independent copy of an object, including the dynamically allocated memory it owns.
// If we modify the copied object's data, the original object remains unchanged.


#include <iostream>
using namespace std;

class Student{
    public:
    int* age;

    Student(int a){
        age=new int(a);
    }
    //Deep copy constructor
    Student(const Student &other){
        age=new int(*other.age);
    }
//const Student& other — receives the original object by reference.
// new int(...) — allocates a separate integer in dynamic memory.
// *other.age — reads the value stored at the original object's pointer.
// The value is copied into the newly allocated memory

    //Destructor
    ~Student(){
        delete age;
    }
//     We used new to allocate dynamic memory, so we use delete to release it when the object is destroyed.
// Without proper memory management, dynamically allocated memory can leak.
};

int main(){
    Student s1(20);
    Student s2=s1;// Deep copy constructor called

    *s2.age=25;
    cout << "s1 age: " << *s1.age << endl; //20
    cout << "s2 age: " << *s2.age << endl; //25

}


// Shallow copy copies the pointer; deep copy allocates separate memory and copies the pointed-to value.