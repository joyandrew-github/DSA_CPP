#pragma once
#include <iostream>
#include "NotificationDecorator.hpp"

class WhatsAppDecorator:public NotificationDecorator{
public:
    WhatsAppDecorator(Notification* notification):NotificationDecorator(notification){}
    void send() override{
        notification->send();
        std::cout<<"WhatsApp Notification "<<std::endl;
    }
    
};