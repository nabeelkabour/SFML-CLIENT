#ifndef NETWORKING_H
#define NETWORKING_H

#include "SFML/Network.hpp"
#include "Observer.h"
#include <iostream>
#include <list>

class Subject;

enum Cmd : uint8_t
{
    ping,
    clientConnected,
    sendName,
    broadcastNewClient,
    syncPrevClients,
    click,
    message,
    move
};

class Client : public Subject
{  
    //sf::Clock clockPing;
    //sf::Clock clockInterval;
    //sf::Time timeLast;
    //sf::Time timer;
    //sf::Time timeDelta;

public:
    sf::TcpSocket socket;
    int8_t socketId = -1;

    Client();

    void update();
};


//class NetworkManager : public Subject
//{
//public:
//    Client client;
//    PlayerManager* playerManager = nullptr;
//
//    void update()
//    {
//        sf::Packet packet;
//
//        auto receiveStatus = client.socket.receive(packet);
//
//        if (receiveStatus == sf::Socket::Status::Done)
//        {
//            uint8_t identifier;
//            packet >> identifier;
//
//            switch (identifier)
//            {
//                //case Cmd::ping:
//                //{
//                //    sf::Time timeReceive = clockPing.getElapsedTime();
//                //    timeDelta = timeReceive - timeLast;
//                //    std::cout << timeDelta.asMicroseconds() << "us\n";
//
//                //    return;
//                //}
//                //break;
//
//            case Cmd::clientConnected:
//            {
//                int8_t receiveId;
//                packet >> receiveId;
//
//                client.clientData.socketId = receiveId;
//
//                notify(&client, Event::CLIENT_CONNECTED);
//                cout << "Connect acknowledge: " << int(client.clientData.socketId) << "\n";
//            }
//            break;
//
//            case Cmd::broadcastNewClient:
//            {
//                int8_t connectingClient;
//                packet >> connectingClient;
//
//                notify(&client, Event::CLIENT_BROADCAST);
//                cout << "New client connected: " << int(connectingClient) << "\n";
//            }
//            break;
//
//            case Cmd::syncPrevClients:
//            {
//                uint8_t clientId;
//                packet >> clientId;
//
//                notify(&client, Event::CLIENT_SYNC);
//                cout << "Synced client: " << int32_t(clientId) << "\n";
//            }
//            break;
//
//            case Cmd::sendName:
//            {
//                int8_t clientId;
//                std::string clientName;
//                packet >> clientId;
//                packet >> clientName;
//
//                for (auto& client : otherClients)
//                {
//                    if (clientId == client->clientData.socketId)
//                    {
//                        //client->clientData.name = clientName;
//                        break;
//                    }
//                }
//
//                notify(&client, Event::CLIENT_NAME);
//            }
//            break;
//            }
//        }
//    }
//};

#endif 