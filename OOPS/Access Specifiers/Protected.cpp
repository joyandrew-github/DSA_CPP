#include <iostream>
#include <iomanip>
using namespace std;

class Employee
{
protected:
    double salary;

public:
    void setSalary(double s)
    {
        salary = s;
    }
    double getSalary()
    {
        return salary;
    }
};

class Developer : public Employee
{
public:
    void display()
    {
        cout << setprecision(7) << salary;
    }
};

int main()
{
    Developer d;
    d.setSalary(12500.13);
    d.display();
    return 0;
}