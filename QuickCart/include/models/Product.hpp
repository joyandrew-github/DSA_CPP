#pragma once //prevents the header from being included repeatedly in the same translation unit.
#include <string>

class Product{
private: //private-protects the product's internal data from direct access.
    //Encapsulation is a fundamental principle of object-oriented programming that restricts direct access to an object's data and methods. By making member variables private, we ensure that they can only be accessed or modified through public methods (getters and setters), which allows for better control over the data and helps maintain the integrity of the object.
    int id;
    std::string name;
    double price;
public:
    Product(int id,const std::string& name,double price); //A constructor is a special member function that initializes an object when it is created.
    //Constructor-No return type
    //const std::string& name avoids making an unnecessary copy of the input string.
    //The const at the end of each getter means that the method promises not to modify the object.
    


    //getter method declarations
    int getId() const;
    std::string getName() const;
    double getPrice() const;

};