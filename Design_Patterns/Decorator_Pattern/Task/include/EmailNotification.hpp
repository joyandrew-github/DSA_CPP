#pragma once
#include <iostream>
#include "Notification.hpp"

class EmailNotification:public Notification{
public:
    void send() override{
        std::cout<<"Sending Email Notification"<<std::endl;
    }
};