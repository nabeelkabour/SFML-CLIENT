#include "PlayerManager.h"
#include "Player.h"
#include "Networking.h"

void PlayerManager::onNotify(sf::Packet packet)
{
	uint8_t identifier;
	packet >> identifier;

	switch (identifier)
	{
	case Cmd::clientConnected:
	{
		int8_t connectingSocket;
		packet >> connectingSocket;

		mainPlayer = new Player(connectingSocket);

		cout << "Main player Connected: " << (int)connectingSocket << "\n";
	}
	break;

	case Cmd::broadcastNewClient:
	{
		int8_t broadcastSocket;
		packet >> broadcastSocket;

		otherPlayers.push_back(new OtherPlayer(broadcastSocket));
		cout << "Other player connected: " << (int)broadcastSocket << "\n";
	}
	break;

	case Cmd::syncPrevClients:
	{
		int8_t syncSocket;
		packet >> syncSocket;

		otherPlayers.push_back(new OtherPlayer(syncSocket));
		cout << "Synced client ID: " << (int)syncSocket << "\n";
	}
	break;

	case Cmd::sendName:
	{
		std::string nameStr;
		int8_t nameId;
		packet >> nameId;
		packet >> nameStr;

		if (client->socketId == nameId)
		{
			mainPlayer->name = nameStr;
			break;
		}

		for (auto& player : otherPlayers)
		{
			if (nameId == player->playerData.playerId)
			{
				player->playerData.name = nameStr;
				break;
			}
		}
	}
	break;
	}
}