#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Employee{
    private:
     int employeeId;
    protected:
      double salary=0.0;
    public:
      string name;


    void setEmployeeId(int e){
        employeeId=e;
    }
    int getEmployeeId(){
        return employeeId;
    }
};
class Developer:public Employee{
    public:
    void setSalary(double s){
        salary=s;
    }
    double getSalary()
    {
        return salary;
    }
    void display(){
        cout<<"Employee ID:"<<getEmployeeId()<<endl;
        cout<<"Employee Name :"<<name<<endl;
        cout<<"Salary :"<<fixed<<setprecision(2)<<salary<<endl;
    }
};
int main(){
    Developer d;
    d.setEmployeeId(101);
    // e.employeeId="101";
    d.name="Joy";
    d.setSalary(45000.00);
    d.display();

}