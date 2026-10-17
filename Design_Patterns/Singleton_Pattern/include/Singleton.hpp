#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <iostream>
class Singleton {
private:
    //Private constructor to prevent instantiation
    Singleton() {
        std::cout << "Singleton instance created." << std::endl;
    }
public:
    //Prevent Copying
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    //Global access point to the instance
    static Singleton& getInstance() {
        static Singleton instance; // Guaranteed to be destroyed and instantiated on first use.
        return instance;
    }

    void showMessage() {
        std::cout << "Hello from Singleton!" << std::endl;
    }
};

#endif // SINGLETON_HPP