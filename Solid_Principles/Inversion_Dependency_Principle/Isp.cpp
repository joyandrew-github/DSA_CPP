#include <bits/stdc++.h>
using namespace std;

class Eatable{
    public:
    virtual void eat()=0;
    virtual ~Eatable()=default;
};

class Flyable{
public:
    virtual void fly()=0;
    virtual ~Flyable()=default;
};

class Walkable{
public:
    virtual void walk()=0;
    virtual ~Walkable()=default;
};

class Swimmable {
public:
    virtual void swim() = 0;
    virtual ~Swimmable() = default;
};

class Dog:public Eatable,public Walkable{
public:
    void eat () override{
        cout<<"Dog is eating"<<endl;
    };
    void walk() override{
        cout<<"Dog is walking"<<endl;
    }
};

class Fish: public Eatable,public Swimmable{
public:
    void eat() override{
        cout<<"Fish is eating"<<endl;
    }
    void swim()override{
        cout<<"Fish is swimming"<<endl;
    }
};

class Eagle:public Eatable,public Flyable,public Walkable{
    public:
    void eat() override{
        cout<<"Eagle is eating"<<endl;
    }
    void fly() override{
        cout<<"Eagle is flying"<<endl;
    }
    void walk() override{
        cout<<"Eagle is walking"<<endl;
    }
};
int main(){
    Dog dog;
    Fish fish;
    Eagle eagle;


    dog.eat();
    dog.walk();


    fish.swim();


    eagle.fly();


    return 0;
}