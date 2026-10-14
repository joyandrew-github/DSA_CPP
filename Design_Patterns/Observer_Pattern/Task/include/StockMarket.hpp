#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstddef>
#include "Observer.hpp"

class StockMarket
{
private:
    std::vector<Observer *> observers;
    std::string stockName;
    double stockPrice;

public:
    StockMarket(const std::string &name, const double &price)
        : stockName(name), stockPrice(price) {}

    void subscribe(Observer *observer)
    {

        if (observer == nullptr)
        {
            return;
        }

        auto it = std::find(
            observers.begin(),
            observers.end(),
            observer);

        if (it != observers.end())
        {
            std::cout << "Observer is already subscribed.\n";
            return; // Important: stop here!
        }

        observers.push_back(observer);
        std::cout << "Observer subscribed successfully.\n";
    }

    void unsubscribe(Observer *observer)
    {
        if (observer == nullptr)
        {
            return;
        }
        auto it = std::find(
            observers.begin(),
            observers.end(),
            observer);
        if (it == observers.end())
        {
            std::cout << "Observer is not subscribed.\n";
            return;
        }

        observers.erase(it);
        std::cout << "Observer unsubscribed successfully.\n";
    }

    void setStockPrice(const double &price)
    {
        stockPrice = price;
        notifyObservers();
    }
    double getStockPrice() const
    {
        return stockPrice;
    }
    std::size_t getInvestorCount() const
    {
        return observers.size();
    }

private:
    void notifyObservers()
    {
        auto snapshot = observers; // Create a snapshot of the current observers
        for (auto observer : snapshot)
        {
            observer->update(stockPrice);
        }
    }
};