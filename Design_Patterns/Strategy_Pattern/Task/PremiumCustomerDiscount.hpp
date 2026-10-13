#pragma once
#include <bits/stdc++.h>
using namespace std;
#include "DiscountStrategy.hpp"

class PremiumCustomerDiscount:public DiscountStrategy{
public:
    double calculateDiscount(double price)override{
         return price - (price * 30.0 / 100.0);
    }
};