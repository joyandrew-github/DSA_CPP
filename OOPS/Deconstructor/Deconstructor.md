1. What is a Destructor in C++?
A destructor is a special member function of a class that is automatically called when an object is destroyed.
It is mainly used to release resources such as dynamically allocated memory, files, and other resources owned by an object.


Important rules:
- The destructor name is the class name preceded by ~.
- It has no return type, not even void.
- It takes no parameters.
- A class can have only one destructor; it cannot be overloaded.
- It is called automatically when an object's lifetime ends.