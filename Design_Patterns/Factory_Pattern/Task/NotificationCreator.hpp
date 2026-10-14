#pragma once
#include <memory>

#include "Notification.hpp"

class NotificationCreator{
public:
    virtual std::unique_ptr<Notification>
    createNotification() = 0;

    virtual ~NotificationCreator() = default;
};