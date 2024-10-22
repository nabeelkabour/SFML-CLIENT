#include "Game.h"
#include "Networking.h"
//#include "Actor.h"
//#include "Resources.h"
//#include "Items.h"
//#include "Particle.h"
//#include "InputHandler.h"
//#include "Command.h"
//#include "Observer.h"
//#include "Prototype.h"
//#include "Player.h"

//Game game;

Game::Game()
{
	sAppName = "SFML CLIENT";
}

bool Game::OnUserCreate()
{
	client.addObserver(&playerManager);
	client.addObserver(&menuManager);

	menuManager.pge = this;
	menuManager.client = &client;
	menuManager.playerManager = &playerManager;

	menuManager.changeMenu(new MainMenu(this, &playerManager, &client, &menuManager));

	playerManager.pge = this;
	playerManager.client = &client;

	return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
	menuManager.update();
	Clear(olc::BLACK);

	client.update();

	menuManager.draw();

	return true;
}