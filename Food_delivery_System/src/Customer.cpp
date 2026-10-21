#include "model/Customer.hpp"
#include <stdexcept>

Customer::Customer(const std::string &name, const std::string &email, const std::string &phoneNumber) : name(name), email(email), phoneNumber(phoneNumber)
{
    if (name.empty() || email.empty() || phoneNumber.empty())
    {
        throw std::invalid_argument("Customer details cannot be empty");
    }
}

// Getters
std::string Customer::getName() const { return name; }
std::string Customer::getEmail() const { return email; }
std::string Customer::getPhoneNumber() const { return phoneNumber; }

// Setters
void Customer::setName(const std::string &newName)
{
    if (newName.empty())
    {
        throw std::invalid_argument("New Name Cannot be empty");
    }
    name = newName;
}
void Customer::setEmail(const std::string &newEmail)
{
    if (newEmail.empty())
    {
        throw std::invalid_argument("New Email Cannot be empty");
    }
    email = newEmail;
}
void Customer::setPhoneNumber(const std::string &newPhoneNumber)
{
    if (newPhoneNumber.empty())
    {
        throw std::invalid_argument("New Phone Number Cannot be empty");
    }
    phoneNumber = newPhoneNumber;
}