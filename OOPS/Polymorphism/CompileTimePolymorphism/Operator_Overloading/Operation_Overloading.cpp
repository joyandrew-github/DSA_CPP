// B. Operator overloading
// Definition: Giving an existing C++ operator a special meaning for user-defined types.
// For example, the + operator normally adds numbers. We can define how it adds two objects.

#include <iostream>
using namespace std;

class Number{
public:
    int value;

    Number(int v):value(v){}
//  This is a constructor that initializes the value variable.
// The expression : value(v) is called a member initializer list. It initializes value with the value passed to the constructor.
Number operator+(const Number& other){
    return Number(value+other.value);

// A. Number operator+
// - operator+ defines how the + operator behaves for Number objects.
// - The return type Number means this function returns a Number object.


// B. const Number& other
// This is the parameter that receives the other object involved in the addition.
// - Number — the parameter is a Number object.
// - & — passes it by reference, avoiding a copy.
// - const — prevents this function from modifying the referenced object through other.


// C. The return statement
// Suppose a + b is executed.
// Inside the overloaded operator function:
// - value refers to a.value, which is 10.
// - other refers to b.
// - other.value is 20.

}
};
int main(){
    Number a(10);
    Number b(20);
    Number c=a+b;
    cout<<c.value;
    return 0;
}