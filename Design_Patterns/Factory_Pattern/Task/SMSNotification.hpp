#pragma once
#include<iostream>
#include "Notification.hpp"

class SMSNotification:public Notification{
public:
    void send(const std::string& message)override{
        std::cout<<"SMS Notification :"<<message<<std::endl;
    }
};