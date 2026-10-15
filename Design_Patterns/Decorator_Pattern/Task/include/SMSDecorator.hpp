#pragma once
#include <iostream>
#include "NotificationDecorator.hpp"

class SMSDecorator:public NotificationDecorator{
public:
    SMSDecorator(Notification* notification):NotificationDecorator(notification){}

    void send()override{
        notification->send();
        std::cout<<"SMS Notification"<<std::endl;
    }
};