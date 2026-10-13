#include <bits/stdc++.h>
using namespace std;

class NotificationChannel
{
public:
    virtual void send(string message) = 0;

    virtual ~NotificationChannel() = default;
};

class EmailNotifier : public NotificationChannel
{
public:
    void send(string message) override
    {
        cout << "Email :" << message << endl;
    }
};

class SMSNotifier : public NotificationChannel
{
public:
    void send(string message) override
    {
        cout << "SMS :" << message << endl;
    }
};

class WhatsAppNotifier : public NotificationChannel
{
public:
    void send(string message) override
    {
        cout << "WhatsApp :" << message << endl;
    }
};

class PushNotifier : public NotificationChannel
{
public:
    void send(string message) override
    {
        cout << "Push Notification :" << message << endl;
    }
};

class MockNotifier : public NotificationChannel
{
public:
    void send(string message) override
    {
        cout << "Mock notification: " << message << endl;
    }
};

class NotificationService
{
private:
    NotificationChannel &channel;

public:
    NotificationService(NotificationChannel &channel) : channel(channel) {}
    void notify(string message)
    {
        channel.send(message);
    }
};

int main()
{
    EmailNotifier email;
    SMSNotifier sms;
    WhatsAppNotifier wp;
    PushNotifier pn;
    MockNotifier mn;

    cout << "Choose notification channel:\n";
    cout << "1. Email\n";
    cout << "2. SMS\n";
    cout << "3. WhatsApp\n";
    cout << "4. Push\n";

    int choice;
    cin >> choice;

    // Select the dependency
    NotificationChannel *selectedChannel = NULL;

    switch (choice)
    {
    case 1:
        selectedChannel = &email;
        break;
    case 2:
        selectedChannel = &sms;
        break;
    case 3:
        selectedChannel = &wp;
        break;
    case 4:
        selectedChannel = &pn;
        break;
    default:
        cout << "Invalid choice!" << endl;
        return 0;
    }

    // One service object, one injected dependency
    NotificationService service(*selectedChannel);
    service.notify("Welcome to our application!");

    return 0;
}