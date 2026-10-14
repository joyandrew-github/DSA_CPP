#include <iostream>
#include "PaymentFactory.hpp"

int main() {
    auto payment = PaymentFactory::createPayment("CASH");

    if (payment) {
        payment->pay(1000);
    }

    return 0;
}
