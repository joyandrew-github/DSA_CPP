// Multiple parents → one child
// Multiple inheritance occurs when one derived class inherits from two or more base classes.
#include<iostream>
using namespace std;
class Printer{
    public:
    void print(){
        cout<<"Printing Document"<<endl;
    }
};
class Scanner{
    public:
    void scan(){
        cout<<"Scanning Document"<<endl;
    }
};

class AllInOne:public Scanner,public Printer{
    public:
    void copy(){
        cout<<"Copyinggg Document"<<endl;
    }
};
int main(){
    AllInOne printer;
    printer.print();
    printer.copy();
    printer.scan();
    return 0;
}