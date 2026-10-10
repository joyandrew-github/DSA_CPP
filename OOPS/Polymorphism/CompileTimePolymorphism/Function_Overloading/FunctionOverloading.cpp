// 2. Compile-time polymorphism
// A. Function overloading
// Definition: Defining multiple functions with the same name but different parameter lists in the same scope.

#include <iostream>
using namespace std;
class Calculator{
    public:
    int add(int a,int b){
        return a+b;
    }
    int add(int a,int b,int c){
        return a+b+c;
    }
    int add(double a,double b,double c,double d){
        return a+b+c+d;
    }

};

int main(){
    Calculator c;
    cout<<c.add(10,20)<<endl;
    cout<<c.add(10,20,25)<<endl;
    cout<<c.add(2.5,5.6,7.8)<<endl;
    return 0;

}


// The compiler selects the appropriate overload based on the arguments.
// Important interview point: You cannot overload functions only by changing their return type.