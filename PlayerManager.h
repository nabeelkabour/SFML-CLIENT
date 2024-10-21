#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include "olcPixelGameEngine.h"
#include "Player.h"
#include "Observer.h"
#include <list>
#include <iostream>

using std::cout;

class Client;
class Player;

class PlayerManager : public Observer
{
public:
	olc::PixelGameEngine* pge;
	Client* client;

	Player* mainPlayer;
	std::list<OtherPlayer*> otherPlayers;

	//virtual void onNotify(Event event, int32_t data)
	virtual void onNotify(Client* client, Event event);
};

#endif