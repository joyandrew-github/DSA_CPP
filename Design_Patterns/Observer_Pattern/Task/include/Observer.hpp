#pragma once

class Observer{
public:
    virtual void update(const double& price)=0;

    virtual~Observer()=default;
};