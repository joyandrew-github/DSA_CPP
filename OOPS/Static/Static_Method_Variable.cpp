#include <iostream>
using namespace std;
class Counter{
    public:
        static int count;
    static void increment(){
        count++;
    }
};
int Counter::count=0;

int main(){
    Counter::increment();
    Counter::increment();
    Counter::increment();
    Counter::increment();
    cout<<Counter::count;
}