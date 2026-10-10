#include<iostream>
using namespace std;
class Notification{
    public:
    string message;
    public:
    virtual void send(string message)=0;
};
class EmailNotification:public Notification{
    public:
    void send(string message) override{
        cout<<"Email Sent :"<<message<<endl;
    }
};

class SMSNotification: public Notification{
    public:
    void send(string message) override{
        cout<<"SMS Sent :"<<message<< endl;
    }
};
int main(){
    EmailNotification En;
    SMSNotification Sm;

    Notification* ptr;//Base cls pointer

    ptr=&En;
    ptr->send("Welcome to our application!");

    ptr=&Sm;
    ptr->send("Your OTP is 1234");

    return 0;    
}