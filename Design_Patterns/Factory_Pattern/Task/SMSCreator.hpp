#pragma once
#include <memory>
#include "NotificationCreator.hpp"
#include "Notification.hpp"
#include "SMSNotification.hpp"

class SMSCreator:public NotificationCreator{
public:
    std::unique_ptr<Notification> createNotification() override{
        return std::make_unique<SMSNotification>();
    }
};


// - unique_ptr = the smart pointer that manages ownership.
// - make_unique = the function that creates the object and gives you that smart pointer.44



//make_unique creates the owned object; unique_ptr manages its lifetime.