#include <iostream>
#include <memory>

#include "Notification.hpp"
#include "EmailNotification.hpp"
#include "SMSDecorator.hpp"
#include "WhatsAppDecorator.hpp"

int main() {
    // Step 1: Create the base notification
    auto email = std::make_unique<EmailNotification>();

    // Step 2: Wrap Email with SMS
    auto sms = std::make_unique<SMSDecorator>(email.get());

    // Step 3: Wrap SMS with WhatsApp
    auto whatsapp =
        std::make_unique<WhatsAppDecorator>(sms.get());

    // Step 4: Send notification through all channels
    whatsapp->send();

    return 0;
}