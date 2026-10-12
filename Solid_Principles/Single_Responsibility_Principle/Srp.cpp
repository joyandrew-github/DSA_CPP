
#include <bits/stdc++.h>
using namespace std;

// Responsibility 1: Store student information
class Student
{
public:
    string name;
    int mark1, mark2;

    Student(string n, int m1, int m2)
        : name(n), mark1(m1), mark2(m2) {}
};

// Responsibility 2: Calculate marks
class MarksCalculator
{
public:
    int calculateTotalMarks(const Student& s)
    {
        return s.mark1 + s.mark2;
    }
};

// Responsibility 3: Print the report
class ReportPrinter
{
public:
    void printReport(const Student& s, int total)
    {
        cout << "Student      : " << s.name << endl;
        cout << "Total Marks  : " << total << endl;
    }
};

// Responsibility 4: Save student information
class StudentRepository
{
public:
    void save(const Student& s)
    {
        cout << "Saving " << s.name
             << " to Joy DB.............." << endl;
    }
};

int main()
{
    Student s("Joy", 88, 90);

    MarksCalculator m;
    ReportPrinter p;
    StudentRepository sr;

    int total = m.calculateTotalMarks(s);

    p.printReport(s, total);
    sr.save(s);

    return 0;
}
