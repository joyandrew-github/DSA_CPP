#pragma once
#include<iostream>
#include "Notification.hpp"

class PushNotification:public Notification{
public:
    void send(const std::string& message)override{
        std::cout<<"Push Notification :"<<message<<std::endl;
    }
};