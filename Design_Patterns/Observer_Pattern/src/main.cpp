#include "Subscriber.hpp"
#include "YouTubeChannel.hpp"

int main(){
    YouTubeChannel channel;

    Subscriber joy("Joy");
    Subscriber veera("Veera");
    Subscriber Amma("Amma");

    channel.subscribe(&joy);
    channel.subscribe(&veera);
    channel.subscribe(&Amma);


    channel.uploadVideo("Observer Pattern in c++");

    std::cout<<"Joy unsubscribes...\n";
    channel.unsubscribe(&joy);

    channel.uploadVideo("Strategy Pattern in c++");


    return 0;
}