#pragma once

class Notification{
public:
    virtual void send()=0;

    virtual ~Notification()=default;
};