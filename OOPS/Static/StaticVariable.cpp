#include <iostream>
#include <string>
using namespace std;
class Student{
    public:
         static int count;
    Student(){
        count++;
    }
};
int Student::count=0;

int main(){
    Student s;
    Student s1;
    Student s2;
    cout<<Student::count;
    return 0;
}

// count belongs to Student class
// Each time an object is created → count++
// Only one count exists, not 3 copies



// Normal variable->Inside each object
// Static variable->Single memory in class area
