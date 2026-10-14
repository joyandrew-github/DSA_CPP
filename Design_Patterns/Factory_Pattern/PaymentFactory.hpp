#pragma once
#include <memory>
#include <string>

#include "Payment.hpp"
#include "UPIPayment.hpp"
#include "CardPayment.hpp"
#include "CashPayment.hpp"
class PaymentFactory
{
public:
    //     static
    // Why do we need it?
    // It allows you to call the function using the class name without creating a PaymentFactory object.

    static std::unique_ptr<Payment>
    createPayment(const std::string &type)
    {
        if(type=="UPI"){
            return std::make_unique<UPIPayment>();
        }
        else if(type=="CARD"){
            return std::make_unique<CardPayment>();
        }
        else if(type=="CASH"){
            return std::make_unique<CashPayment>();
        }
        return nullptr;
    }
};