#pragma once
#include "Notification.hpp"

class NotificationDecorator:public Notification{
protected:
    Notification* notification;
public:
    NotificationDecorator(Notification* notification)
    : notification(notification) {}

    virtual ~NotificationDecorator()=default;
};