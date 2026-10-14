#pragma once
#include <memory>
#include "NotificationCreator.hpp"
#include "Notification.hpp"
#include "PushNotification.hpp"

class PushCreator:public NotificationCreator{
public:
    std::unique_ptr<Notification> createNotification()override{
        return std::make_unique<PushNotification>();
    }
};