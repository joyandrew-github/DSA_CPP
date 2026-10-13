#include <bits/stdc++.h>
using namespace std;

class PowerControl
{
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;

    virtual ~PowerControl() = default;
};

class AdjustBrightnessLevel
{
public:
    virtual void adjustBrightness(int level) = 0;

    virtual ~AdjustBrightnessLevel() = default;
};

class PhotoGraphble
{
public:
    virtual void takePhoto() = 0;
    virtual ~PhotoGraphble() = default;
};

class Printable
{
public:
    virtual void takePrint() = 0;
    virtual ~Printable() = default;
};

class SmartLight : public PowerControl, public AdjustBrightnessLevel
{
public:
    void turnOn() override
    {
        cout << "Smart light turned ON" << endl;
    }
    void turnOff() override
    {
        cout << "Smart light turned OFF\n";
    }
    void adjustBrightness(int level) override
    {
        cout << "Brightness set to " << level << '\n';
    }
};

class SecurityCamera : public PowerControl, public PhotoGraphble
{
public:
    void turnOn() override
    {
        cout << "Security light turned ON" << endl;
    }
    void turnOff() override
    {
        cout << "Security light turned OFF\n";
    }
    void takePhoto() override
    {
        cout<<"Taking Photos"<<endl;
    }
};

class SmartPrinter : public PowerControl, public Printable
{
public:
    void turnOn() override
    {
        cout << "SmartPrinter light turned ON" << endl;
    }
    void turnOff() override
    {
        cout << "SmartPrinter light turned OFF\n";
    }
    void takePrint() override
    {
        cout<<"Taking printout"<<endl;
    }
};

int main()
{
    SmartLight smart;
    SecurityCamera security;
    SmartPrinter printer;

    smart.turnOff();
    smart.adjustBrightness(5);

    security.turnOn();
    security.takePhoto();
    security.turnOff();

    printer.turnOn();
    printer.takePrint();
    printer.turnOff();
    return 0;
}