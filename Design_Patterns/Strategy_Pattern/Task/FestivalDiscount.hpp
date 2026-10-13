#pragma once
#include <bits/stdc++.h>
using namespace std;
#include "DiscountStrategy.hpp"

class FestivalDiscount:public DiscountStrategy{
public:
    double calculateDiscount(double price)override{
         return price - (price * 20.0 / 100.0);
    }
};