#pragma once
#include<iostream>
#include "Notification.hpp"

class EmailNotification:public Notification{
public:
    void send(const std::string& message)override{
        std::cout<<"Email Notification :"<<message<<std::endl;
    }
};