#include "Networking.h"

Client::Client() {}

void Client::update()
{
    sf::Packet packet;

    auto receiveStatus = socket.receive(packet);

    if (receiveStatus == sf::Socket::Status::Done)
    {
        notify(packet);
    }
}