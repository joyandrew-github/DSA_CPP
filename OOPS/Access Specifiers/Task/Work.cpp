#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class course
{
    public:
        string CourseName;
        double fees;
        int duration;
    void setCourse(string c,double f,int d)
    {
        CourseName=c;
        fees=f;
        duration=d;

    }
    void display()
    {
        cout<<"Course Name: "<<CourseName<<endl;
        cout<<"Course Fee: "<<fixed<<setprecision(2)<<fees<<endl;
        cout<<"Duration :"<<duration<<" weeks "<<endl;
    }
    
};
int main()
{
    course c;
    c.setCourse("Full Stack Development",15000.50,12);
    c.display();
    return 0;
}