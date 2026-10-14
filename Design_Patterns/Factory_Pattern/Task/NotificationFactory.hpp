// #pragma once
// #include <iostream>
// #include <memory>
// #include "Notification.hpp"
// #include "EmailNotification.hpp"
// #include "SMSNotification.hpp"
// #include "PushNotification.hpp"

// class NotificationFactory{
// public:
//     static std::unique_ptr<Notification>
//     createNotification(const std::string& type){
//         if(type=="SMS"){
//             return std::make_unique<SMSNotification>();
//         }
//         else if(type=="EMAIL"){
//             return std::make_unique<EmailNotification>();
//         }
//         else if(type=="PUSH"){
//             return std::make_unique<PushNotification>();
//         }
//         return nullptr;
//     }
// };