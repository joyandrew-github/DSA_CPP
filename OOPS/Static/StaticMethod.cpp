#include <iostream>
using namespace std;

class Math {
public:
    static int add(int a, int b) {
        return a + b;
    }
};

int main() {
    Math m;
    // cout<<m.add(10,20);
    cout << Math::add(10, 20); // Output: 30
}