Rules of constructors
- The constructor name must be the same as the class name.
- A constructor has no return type, not even void.
- It is called automatically when an object is created.
- Constructors can be overloaded.
- Constructors can accept parameters.
- Constructors cannot be static or virtual.

Types of constructors in C++
1. Default Constructor
A constructor that can be called without passing arguments.
Example: Student()

2. Parameterized Constructor
A constructor that accepts arguments to initialize an object with specific values.
Example: Student(int a)

3. Copy Constructor
Creates a new object using an existing object of the same class.
Example: Student(const Student& other)