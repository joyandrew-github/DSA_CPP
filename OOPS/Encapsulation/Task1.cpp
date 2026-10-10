#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    int rollNumber=0;
    int marks=0;
public:
    void setName(string n)
    {
        name = n;
    }
    string getName()
    {
        return name;
    }
    void setRollNumber(int r)
    {   if(r>0)
        rollNumber = r;
        else cout<<"Roll Number must be positive";
    }
    int getRollNumber()
    {
        return rollNumber;
    }
    void setMarks(int m)
    {
         if (m >= 0 && m <= 100)
        {
            marks = m;
        }
        else
        {
            cout << "Invalid marks!" << endl;
        }
    }
    int getMarks()
    {
        return marks;
    }
    void displayDetails()
    {
        cout << "Student Name :" << name<<endl;
        cout << "Roll No :" << rollNumber<<endl;
        cout << "Marks :" << marks<<endl;
    }
};

int main()
{
    Student s;

    s.setName("Joy");
    s.setRollNumber(-1);
    s.setMarks(85);

    s.displayDetails();

    s.setMarks(150);

    s.displayDetails();
}