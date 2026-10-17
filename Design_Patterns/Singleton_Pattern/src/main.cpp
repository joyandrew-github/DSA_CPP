#include "Singleton.hpp"

int main(){
    Singleton& obj1 = Singleton::getInstance();
    Singleton& obj2= Singleton::getInstance();
    obj1.showMessage();
    std::cout<<(&obj1==&obj2)<<'\n';
    return 0;
}