#pragma once
#include <bits/stdc++.h>
using namespace std;
#include "DiscountStrategy.hpp"

class RegularDiscount:public DiscountStrategy{
public:
    double calculateDiscount(double price)override{
        return price;
    }
};