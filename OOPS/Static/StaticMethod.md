🔹 STATIC METHODS
🔸 What is a static method?
A static method:
- Belongs to the class
- Can be called without object
- Can access only static variables/methods
❌ Cannot access non-static members directly



🔸 Why static methods cannot access non-static variables?
class Test {
public:
    int x = 10;
    static void show() {
        // cout << x; ❌ ERROR
    }
};

Reason:
- Static method has no object
- x exists inside object
- So compiler doesn’t know which object's x to use