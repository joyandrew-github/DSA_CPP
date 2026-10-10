// 2. Multilevel inheritance
// Parent → child → grandchild

// Multilevel inheritance occurs when a class inherits from another derived class, creating an inheritance chain.
#include<iostream>
using namespace std;
class Person{
    public:
    string name;
    Person(string n):name(n){}
    // Person(string n){
    //     name=n;
    // }
};
class Employee: public Person{
    public:
    int employeeId;

    Employee(string n,int id):Person(n),employeeId(id){}
};

class Manager : public Employee{
    public:
    Manager(string n,int id):Employee(n,id){}

    void display(){
        cout<<"Name :"<<name<<endl;
        cout<<"Employee ID :"<<employeeId<<endl;
        cout<<"Role :Manager"<<endl;
    }
};
int main(){

    Manager m("Joy",101);
    m.display();
    return 0;

}