#include <iostream>
#include <memory>
#include <string>
#include "SimpleCoffee.hpp"
#include "MilkDecorator.hpp"
#include "WhippedCreamDecorator.hpp"

int main()
{
    std::unique_ptr<Coffee> coffee =
        std::make_unique<SimpleCoffee>();

    std::cout << coffee->getDescription()
              << " : Rs." << coffee->getCost() << '\n';

     coffee = std::make_unique<MilkDecorator>(coffee.release());
    std::cout << coffee->getDescription()
              << " : Rs." << coffee->getCost() << '\n';

     coffee = std::make_unique<WhippedCreamDecorator>(coffee.release());
    std::cout << coffee->getDescription()
              << " : Rs." << coffee->getCost() << '\n';

    return 0;
}