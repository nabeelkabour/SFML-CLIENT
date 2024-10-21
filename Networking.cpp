#include "Networking.h"

Client::Client() {}

void Client::update()
{
    sf::Packet packet;

    auto receiveStatus = socket.receive(packet);

    if (receiveStatus == sf::Socket::Status::Done)
    {
        uint8_t identifier;
        packet >> identifier;

        switch (identifier)
        {
            //case Cmd::ping:
            //{
            //    sf::Time timeReceive = clockPing.getElapsedTime();
            //    timeDelta = timeReceive - timeLast;
            //    std::cout << timeDelta.asMicroseconds() << "us\n";

            //    return;
            //}
            //break;

        case Cmd::clientConnected:
        {
            int8_t receiveId;
            packet >> receiveId;

            socketId = receiveId;

            notify(this, Event::CLIENT_CONNECTED);
            std::cout << "Connect acknowledge: " << int(socketId) << "\n";
        }
        break;

        case Cmd::broadcastNewClient:
        {
            int8_t connectingClient;
            packet >> connectingClient;

            notify(this, Event::CLIENT_BROADCAST);
            std::cout << "New client connected: " << int(connectingClient) << "\n";
        }
        break;

        case Cmd::syncPrevClients:
        {
            uint8_t clientId;
            packet >> clientId;

            notify(this, Event::CLIENT_SYNC);
            std::cout << "Synced client: " << int32_t(clientId) << "\n";
        }
        break;

        case Cmd::sendName:
        {
            int8_t clientId;
            std::string clientName;
            packet >> clientId;
            packet >> clientName;

            notify(this, Event::CLIENT_NAME);
        }
        break;
        }
    }
}