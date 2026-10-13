#include <bits/stdc++.h>
using namespace std;
#include "DiscountStrategy.hpp"
#include "RegularDiscount.hpp"
#include "FestivalDiscount.hpp"
#include "PremiumCustomerDiscount.hpp"
#include "ShoppingCart.hpp"

int main()
{
    RegularDiscount rd;
    FestivalDiscount fd;
    PremiumCustomerDiscount pcd;


    ShoppingCart cart(&rd);

    cout << "Regular Price: Rs."
              << cart.checkout(1000) << '\n';

    cart.setStrategy(&fd);
    cout << "Festival Price: Rs."
              << cart.checkout(1000) << '\n';

    cart.setStrategy(&pcd);
    cout << "Premium Customer Price: Rs."
              << cart.checkout(1000) << '\n';

    return 0;
}
