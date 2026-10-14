#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <string>
#include "Observer.hpp"

class YouTubeChannel
{
private:
    std::vector<Observer *> observers;
    std::string latestVideo;

public:
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
        auto snapshot = observers;

        for (Observer *observer : snapshot)
        {
            observer->update(latestVideo);
        }
    }
};