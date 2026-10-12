#include <bits/stdc++.h>
using namespace std;

class Employee
{
public:
    string name;
    double salary;

    Employee(string n, double s) : name(n), salary(s) {}
};

class SalaryCalculator
{
public:
    double calculateAnnualSalary(const Employee &e)
    {
        if (e.salary <= 0)
        {
            return 0.0;
        }
        return (e.salary * 12);
    }
};

class PermenantEmployee
{
public:
    double calculateBonus() const
    {
        return 50000;
    }
};

class ContractEmployee
{
public:
    double calculateBonus() const
    {
        return 20000;
    }
};

class EmployeePrinter
{
public:
    void printDetails(const Employee &e, double annualSalary)
    {
        cout << "Employee Name  : " << e.name << endl;
        cout << "Monthly Salary : " << fixed
             << setprecision(2) << e.salary << endl;
        cout << "Annual Salary  : " << annualSalary << endl;
    }
};

class EmployeeRepository
{
public:
    void save(const Employee &e)
    {
        cout << "Saving Employeee Salaryy........." << e.name;
    }
};
int main()
{
    Employee e1("Joy", 50000);
    Employee e2("Alex", 40000);

    SalaryCalculator sc;
    PermenantEmployee pe;
    ContractEmployee ce;
    EmployeePrinter printer;

    double permanentTotal =
        sc.calculateAnnualSalary(e1) + pe.calculateBonus();

    double contractTotal =
        sc.calculateAnnualSalary(e2) + ce.calculateBonus();

    printer.printDetails(e1, permanentTotal);
    cout << endl;
    printer.printDetails(e2, contractTotal);

    return 0;
}