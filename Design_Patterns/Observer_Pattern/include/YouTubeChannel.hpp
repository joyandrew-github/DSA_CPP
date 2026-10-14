#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Observer.hpp"

class YouTubeChannel{
public:
    std::vector<Observer*>observers;
    std::string latestVideo;

    void subscribe(Observer* observer){
        observers.push_back(observer);
    }

    void unsubscribe(Observer* observer){
        observers.erase(
            remove(observers.begin(),observers.end(),observer),
            observers.end()
        );
    }

    void uploadVideo(const std::string& video){
        latestVideo=video;
        std::cout<<"New video Uploaded: "
                <<latestVideo<<std::endl;
        
        notifyObservers();
    }
private:
    void notifyObservers(){
        for(Observer* observer:observers){
            observer->update(latestVideo);
        }
    } 
};