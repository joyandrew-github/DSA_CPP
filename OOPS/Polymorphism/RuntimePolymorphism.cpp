#include <iostream>
using namespace std;

class Animal{
    public:
        virtual void sound(){
            cout<<"Animal Makes Sound"<<endl;
        }

};
class Dog : public Animal{
    public:
        void sound() override{
            cout<<"Dog Barks"<<endl;
        }
};
class Cat: public Animal{
    public:
    void sound()override{
        cout<<"Cat Meow"<<endl;
    }
};

int main(){
    Dog d;
    Cat c;
    Animal* ptr;
    ptr= &d;
    ptr->sound();


    ptr=&c;
    ptr->sound();
}