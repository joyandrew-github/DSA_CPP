#include <bits/stdc++.h>
using namespace std;

class Order
{
private:
    vector<double> prices;

public:
    void addItems(double price)
    {
        prices.push_back(price);
    }
    const vector<double> &getPrices() const
    {
        return prices;
    }
};

class OrderCalculator
{
public:
    double calculateTotal(const Order &order)
    {
        double tot = 0;
        for (double price : order.getPrices())
        {
            tot += price;
        }
        return tot;
    }
};

class PaymentProcessor
{
public:
    virtual bool pay(double amount) = 0;
    virtual ~PaymentProcessor() = default;
};

class UPIPayment : public PaymentProcessor
{
public:
    bool pay(double amount) override
    {
        cout << "Paid: " << amount << " Using UPI" << endl;
        return true;
    }
};

class CardPayment : public PaymentProcessor
{
public:
    bool pay(double amount) override
    {
        cout << "Paid  :" << amount << " Using Card"<<endl;
        return false;
    }
};

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

class OrderService
{
private:
    OrderCalculator &calculator;
    PaymentProcessor &process;
    NotificationChannel &notification;

public:
    OrderService(OrderCalculator &calculator, PaymentProcessor &process, NotificationChannel &notification)
        : calculator(calculator),
          process(process),
          notification(notification) {}
    void checkout(const Order &order)
    {
        calculator.calculateTotal(order);
        double total = calculator.calculateTotal(order);
        cout << "Order total: " << total << endl;
        // process.pay(total);
        bool success = process.pay(total);
        if (success)
        {
            notification.send("Your order has been confirmed!");
        }
        else
        {
            cout << "Payment failed!" << endl;
        }
    }
};
int main()
{
    Order order;
    order.addItems(500);
    order.addItems(300);
    order.addItems(200);

    OrderCalculator calculator;
    // UPIPayment payment;
    CardPayment payment;
    EmailNotifier notifier;

    OrderService service(calculator, payment, notifier);
    service.checkout(order);

    return 0;
}