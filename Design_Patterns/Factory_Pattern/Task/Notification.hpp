#pragma once
#include <string>
class Notification{
public:
    virtual void send(const std::string& message)=0;

    virtual ~Notification()=default;  
};