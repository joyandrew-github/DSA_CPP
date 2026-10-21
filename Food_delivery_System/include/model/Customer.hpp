#pragma once
#include <string>

class Customer
{
private:
    std::string name;
    std::string email;
    std::string phoneNumber;
public:
    Customer(const std::string &name, const std::string &email, const std::string &phoneNumber);

    // Getters
    std::string getName() const;
    std::string getEmail() const;
    std::string getPhoneNumber() const;

    // Setters
    void setName(const std::string &newName);
    void setEmail(const std::string &newEmail);
    void setPhoneNumber(const std::string &newPhoneNumber);
};