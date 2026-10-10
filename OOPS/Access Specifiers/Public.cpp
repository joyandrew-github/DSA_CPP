// Members declared as public can be accessed from anywhere where the object is accessible.

#include<iostream>
#include<string>
using namespace std;
class student{
    public:
        string name;
        void display()
        {
            cout<<name;
        }
};

int main()
{
    student s;
    s.name="Joy"; //Allowed
    s.display(); //Allowed
}

//Public = Everyone can access
