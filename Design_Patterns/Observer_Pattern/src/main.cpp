#include <iostream>
#include "Subscriber.hpp"
#include "YouTubeChannel.hpp"

int main()
{
    YouTubeChannel channel;

    Subscriber joy("Joy");
    Subscriber veera("Veera");
    Subscriber Amma("Amma");

    // channel.subscribe(&joy);
    channel.subscribe(&veera);
    channel.subscribe(&Amma);

    std::cout << " Subscribe Count :" << channel.getSubcriberCount() << std::endl;

    // Try subscribing Alice again
    channel.subscribe(&joy);

    std::cout << "Subscriber count: "
              << channel.getSubcriberCount() << '\n';

    channel.uploadVideo("Observer Pattern in c++");

    std::cout << "Joy unsubscribes...\n";
    channel.unsubscribe(&joy);

    std::cout << "Subscriber count: "
              << channel.getSubcriberCount() << '\n';

    channel.uploadVideo("Strategy Pattern in c++");

    channel.unsubscribe(&veera);
        std::cout << "Final Subscriber count: "
              << channel.getSubcriberCount() << '\n';
    return 0;
}