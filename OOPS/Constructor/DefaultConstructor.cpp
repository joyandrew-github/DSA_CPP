//A constructor in C++ is a special member function of a class that is automatically called when an object is created. 
//It is mainly used to initialize the data members of an object.

//A default constructor can be called without arguments.
#include<iostream>
using namespace std;
class Employee{
    public:
        int id;
        string name;

    Employee(){
        id=101;
        name="Joy";
    }
    void display(){
        cout<<id<<' '<<name<<' '<<endl;
    }

};
int main(){
    Employee e;
    e.display();

    Employee e1;
    e1.display();
    return 0;
}