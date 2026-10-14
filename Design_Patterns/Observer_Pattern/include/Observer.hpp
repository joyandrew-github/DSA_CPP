#pragma once
#include <string>

class Observer{
public:
    virtual void update(const std::string& video)=0;

    virtual ~Observer()=default;
};