#include <bits/stdc++.h>
using namespace std;

class Bird
{
public:
    virtual void eat()
    {
        cout << "Bird is Eating" << endl;
    }
    virtual ~Bird() = default;
};

class Flyable
{
public:
    virtual void fly() = 0;
    virtual ~Flyable() = default;
};

class Sparrow : public Bird, public Flyable
{
    void fly() override{
        cout<<"Sparrow is flying"<<endl;
    }
};

class Penguin:public Bird{
public:
void swim(){
    cout<<"Penguin is Swimming";
}
};

void makeBirdEat(Bird& bird){
    bird.eat();
}

void makeBirdFly(Flyable& bird){
    bird.fly();
}

int main(){
    Sparrow sparrow;
    Penguin penguin;

    makeBirdEat(sparrow);
    makeBirdEat(penguin);

    makeBirdFly(sparrow);

}