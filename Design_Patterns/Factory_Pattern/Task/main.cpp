// #include <iostream>
// #include "NotificationFactory.hpp"

// int main(){
//     auto notification=NotificationFactory::createNotification("WHATSAPP");
//     if(notification){
//         notification->send("Hello Joy");
//     }
//     else{
//         std::cout<<"Invalid Type";
//     }
//     return 0;
// }

#include <iostream>
#include <memory>
#include "NotificationCreator.hpp"
#include "SMSCreator.hpp"
#include "PushCreator.hpp"

int main()
{
     std::unique_ptr<NotificationCreator> creator = std::make_unique<SMSCreator>();
     std::unique_ptr<NotificationCreator> creator2 = std::make_unique<PushCreator>();

    auto notification = creator->createNotification();
    auto notification2=creator2->createNotification();

    notification->send("Hello Joy");
    notification2->send("Hello Juli");
    return 0;
}