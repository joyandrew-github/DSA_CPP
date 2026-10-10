// Members declared as private can be accessed only inside the same class.
#include <iostream>
#include <string>
using namespace std;

class student
{
private:
    int age;

public:
    void setAge(int a)
    {
        age = a;
    }
    int getAge()
    {
        return age;
    }
};
int main()
{
    student s;
    // s.age=20;
    s.setAge(20);
    cout << s.getAge();
}