#include <iostream>
#include "StockMarket.hpp"
#include  "Investor.hpp"

int main()
{
    StockMarket stockMarket("AAPL", 150.0);

    Investor investor1("Alice");
    Investor investor2("Bob");

    stockMarket.subscribe(&investor1);
    stockMarket.subscribe(&investor2);

    std::cout << "Investor count: "
              << stockMarket.getInvestorCount() << '\n';
    
    stockMarket.setStockPrice(155.0);
    std::cout << "Final stock price: " << stockMarket.getStockPrice() << '\n';

    stockMarket.unsubscribe(&investor1);
    std::cout << "Investor count: "
              << stockMarket.getInvestorCount() << '\n';
    stockMarket.setStockPrice(160.0);   

    std::cout << "Final stock price: " << stockMarket.getStockPrice() << '\n';  

    return 0;
}