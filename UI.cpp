#include "UI.h"
#include <string>

Menu::Menu(olc::PixelGameEngine* _pge, PlayerManager* _playerManager, Client* _client, MenuManager* _menuManager) :
	pge(_pge), playerManager(_playerManager), client(_client), menuManager(_menuManager) {}

void Menu::update()
{
	guiManager.Update(pge);
}

MainMenu::MainMenu(olc::PixelGameEngine* _pge, PlayerManager* _playerManager, Client* _client, MenuManager* _menuManager) :
	Menu(_pge, _playerManager, _client, _menuManager)
{
	//pge = _pge;
	//playerManager = _playerManager;
	//client = _client;
	//menuManager = _menuManager;

	titleLabel = new olc::QuickGUI::Label(guiManager, "Main Menu",
		{ float(500) / 2.f, 25.f }, { 50.f, 16.f });

	startButton = new olc::QuickGUI::Button(guiManager, "Start",
		{ 500.f / 2.f, 150.f }, { 50.f, 32.f });
}

void MainMenu::update()
{
	Menu::update();

	if (startButton->bReleased)
	{
		menuManager->changeMenu(new GameMenu(pge, playerManager, client, menuManager));
	}
}

void MainMenu::onNotify(Client* client, Event event)
{

}

GameMenu::GameMenu(olc::PixelGameEngine* _pge, PlayerManager* _playerManager, Client* _client, MenuManager* _menuManager) :
	Menu(_pge, _playerManager, _client, _menuManager)
{
	//pge = _pge;
	//playerManager = _playerManager;
	//client = _client;
	//menuManager = _menuManager;

	enterIpLabel = new olc::QuickGUI::Label(guiManager, "Enter IP address and port:",
		{ 250.f, 25.f }, { 50.f, 32.f });

	ipText = new olc::QuickGUI::TextBox(guiManager, "127.0.0.1", 
		{ 250.f, 75.f }, { 125.f, 32.f });

	portText = new olc::QuickGUI::TextBox(guiManager, "2000",
		{ 250.f, 150.f }, { 125.f, 32.f });

	nameText = new olc::QuickGUI::TextBox(guiManager, "Name",
		{ 250.f, 175.f }, { 125.f, 32.f });

	joinButton = new olc::QuickGUI::Button(guiManager, "Join",
		{ 250.f, 250.f }, { 50.f, 32.f });

	backButton = new olc::QuickGUI::Button(guiManager, "Back",
		{ 250.f, 300.f }, { 50.f, 32.f });

	playerListBox = new olc::QuickGUI::ListBox(guiManager, playerList,
		{ 150.0f, 400.0f }, { 100.0f, 54.0f });
}

void GameMenu::update()
{
	Menu::update();

	if (joinButton->bReleased)
	{
		sf::Socket::Status status = client->socket.connect(ipText->sText, std::stoi(portText->sText));

		sf::Packet packetTx;
		packetTx << Cmd::sendName << nameText->sText;
		client->socket.send(packetTx);
	}
	else if (backButton->bReleased)
	{
		menuManager->changeMenu(new MainMenu(pge, playerManager, client, menuManager));
	}
}

void GameMenu::onNotify(Client* client, Event event)
{
	switch (event)
	{
	case Event::CLIENT_CONNECTED:
	{
		playerList.push_back(nameText->sText);
	}
	break;

	//case Event::CLIENT_SYNC:
	case Event::CLIENT_BROADCAST:
	{
		//playerList.push_back("player" + std::to_string(client->socketId));
		playerList.push_back("text");
	}
	break;

	case Event::CLIENT_SYNC:
	{
		//playerList.push_back("player" + std::to_string(client->socketId));
		//playerList.push_back("player" + std::to_string(client->socketId));
		playerList.push_back("text");
	}
	break;
	}
}

void MenuManager::onNotify(Client* client, Event event)
{
	currentMenu->onNotify(client, event);
}

MenuManager::MenuManager()
{
	changeMenu(new MainMenu(pge, playerManager, client, this));
}

void MenuManager::changeMenu(Menu* newMenu)
{
	delete currentMenu;
	currentMenu = newMenu;
}

void MenuManager::update()
{
	currentMenu->update();
}

void MenuManager::draw()
{
	currentMenu->guiManager.Draw(pge);
}