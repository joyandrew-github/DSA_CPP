#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Observer.hpp"

class YouTubeChannel
{
public:
    std::vector<Observer *> observers;
    std::string latestVideo;

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
            std::cout << "Subscriber is already subscribed.\n";
            return; // Important: stop here!
        }

        observers.push_back(observer);
        std::cout << "Subscriber subscribed successfully.\n";
    }

    void unsubscribe(Observer *observer)
    {
        auto it = std::find(
            observers.begin(),
            observers.end(),
            observer);
        if (it == observers.end())
        {
            std::cout << "Subscriber is not subscribed.\n";
            return;
        }

        observers.erase(it);
        std::cout << "Subscriber unsubscribed successfully.\n";
    }
    std::size_t getSubcriberCount() const
    {
        return observers.size();
    }

    void uploadVideo(const std::string &video)
    {
        latestVideo = video;
        std::cout << "New video Uploaded: "
                  << latestVideo << std::endl;

        notifyObservers();
    }

private:
    void notifyObservers()
    {
        for (Observer *observer : observers)
        {
            observer->update(latestVideo);
        }
    }
};