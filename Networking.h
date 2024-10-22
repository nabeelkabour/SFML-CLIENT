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

#endif 