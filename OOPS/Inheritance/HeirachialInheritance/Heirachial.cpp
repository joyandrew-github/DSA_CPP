// // Hierarchical inheritance occurs when two or more derived classes inherit from the same base class.
// One parent → multiple children

#include <iostream>
using namespace std;
class Employee{
    public:
    string name;
    Employee(string n):name(n){}
    void displayName(){
        cout<<"Employee :"<<name<<endl;
    }

};
class Developer : public Employee{
    public:
    Developer(string n):Employee(n){}
    void writeCode(){
        cout<<name<<" is writing code"<<endl;
    }
};

class Manager : public Employee{
    public:
    Manager(string n):Employee(n){}
    void manageTeam(){
        cout<<name<<" is managing the team"<<endl;
    }
};
int main(){
    Developer d("Joy");
    Manager m("JoyKing");
    d.displayName();
    d.writeCode();


    m.displayName();
    m.manageTeam();

    return 0;
}