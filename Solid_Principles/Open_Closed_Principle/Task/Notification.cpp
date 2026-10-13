#include <bits/stdc++.h>
using namespace std;
enum class Priority
{
    NORMAL,
    URGENT
};

string priorityToString(Priority pr)
{
    switch (pr)
    {
    case Priority::NORMAL:
        return "NORMAL";
    case Priority::URGENT:
        return "URGENT";
    }
    return "UNKNOWN";
}
class NotificationChannel
{
public:
    virtual void send(const string message,Priority pr)const = 0;

    virtual ~NotificationChannel() = default;
};

class EmailNotification : public NotificationChannel
{
public:
    void send(const string message,Priority pr) const override
    {
        cout << "Email Notification" << message << " [" << priorityToString(pr) << "]" " Sent Sucessfully" << endl;
    }
};

class SMSNotification : public NotificationChannel
{
public:
    void send(const string message,Priority pr) const override
    {
        cout << "SMS Message Notification " << message << " [" << priorityToString(pr) << "]" " Sent Suceesfully" << endl;
    }
};

class WhatsAppNotification : public NotificationChannel
{
public:
    void send(const string message,Priority pr) const override
    {
        cout << "Whatsapp Notification " << message << " [" << priorityToString(pr) << "]"<< " Sent Sucessfully" << endl;
    }
};

class PushNotification : public NotificationChannel
{
public:
    void send(const string message,Priority pr) const override
    {
        cout << "Push Notification: " << message << " [" << priorityToString(pr) << "]"<< endl;
    }
};

class NotificationService
{
public:
    void service(const NotificationChannel &channel,const string message,const Priority& pr) const
    {
        channel.send(message,pr);
    }
};

int main()
{
    NotificationService ns;
    EmailNotification em;
    SMSNotification sm;
    WhatsAppNotification wn;
    PushNotification pn;

    ns.service(em, "Welcome!", Priority::NORMAL);
    ns.service(sm, "Your otp is 1234", Priority::URGENT);
    ns.service(wn, "Your order has shipped", Priority::NORMAL);
    ns.service(pn, "Your package has arrive", Priority::URGENT);

    return 0;
}