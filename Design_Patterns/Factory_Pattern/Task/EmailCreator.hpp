#pragma once
#include <memory>

#include "EmailNotification.hpp"
#include "NotificationCreator.hpp"


class EmailCreator:public NotificationCreator{
public:
    std::unique_ptr<Notification> createNotification()override{
        return std::make_unique<EmailNotification>();
    }
};