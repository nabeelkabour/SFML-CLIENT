#include "PlayerManager.h"
#include "Player.h"
#include "Networking.h"

void PlayerManager::onNotify(Client* client, Event event)
{
	switch (event)
	{
	case Event::CLIENT_CONNECTED:
	{
		mainPlayer = new Player(client->socketId);

		cout << "Main player Connected: " << (int)client->socketId << "\n";
	}
	break;

	case Event::CLIENT_BROADCAST:
	{
		otherPlayers.push_back(new OtherPlayer(client->socketId));
		cout << "Other player connected: " << (int)client->socketId << "\n";
	}
	break;

	case Event::CLIENT_SYNC:
	{
		otherPlayers.push_back(new OtherPlayer(client->socketId));
		cout << "Synced client ID: " << (int)client->socketId << "\n";
	}
	break;

	case Event::CLIENT_NAME:
	{
		for (auto& player : otherPlayers)
		{
			//if(player->playerId == )
		}
	}
	break;
	}
}