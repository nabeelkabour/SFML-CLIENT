#ifndef GAME_H
#define GAME_H

#include "olcPixelGameEngine.h"
//#include "olcPGEX_Gamepad.h"
//#include "olcPGEX_MiniAudio.h"
#include "SFML/Network.hpp"
#include <ctime>
//#include "Actor.h"
//#include "InputHandler.h"
//#include "Observer.h"
//#include "Player.h"
#include "Networking.h"
#include "PlayerManager.h"
#include "Player.h"
#include "UI.h"

#define SCREENWIDTH 500
#define SCREENHEIGHT 500

class Game : public olc::PixelGameEngine
{
public: 
	Client client;
	MenuManager menuManager;
	PlayerManager playerManager;

	Game();
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
};

//extern Game game;

#endif