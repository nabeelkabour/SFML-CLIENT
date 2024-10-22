#ifndef UI_H
#define UI_H

#include "olcPGEX_QuickGUI.h"
#include "olcPixelGameEngine.h"
#include "Networking.h"
#include "PlayerManager.h"

//class UiManager
//{
//public:
//	olc::QuickGUI::Manager guiManager;
//
//	olc::QuickGUI::Label* addressLabel = nullptr;
//	olc::QuickGUI::TextBox* addressText = nullptr;
//	olc::QuickGUI::TextBox* portText = nullptr;
//	//olc::QuickGUI::Button* hostGameButton = nullptr;
//	olc::QuickGUI::Button* joinGameButton = nullptr;
//
//	UiManager()
//	{
//		addressLabel = new olc::QuickGUI::Label(guiManager, "Enter server IP address and port:",
//			{ 0.f, 25.f }, { 50.f, 16.f });
//
//
//		addressText = new olc::QuickGUI::TextBox(guiManager, "127.0.0.1",
//			{ 0.f, 50.f }, { 150.f, 32.f });
//
//		portText = new olc::QuickGUI::TextBox(guiManager, "2000",
//			{ 0.f, 100.f }, { 150.f, 32.f });
//
//		joinGameButton = new olc::QuickGUI::Button(guiManager, "Join",
//			{ 0.f, 150.f }, { 50.f, 32.f });
//
//		//hostGameButton = new olc::QuickGUI::Button(guiManager, "Host",
//		//	{ 0.f, 150.f }, { 50.f, 32.f });
//
//
//		//addressText->nAlign = olc::QuickGUI::TextBox::Alignment::Centre;
//		addressLabel->nAlign = olc::QuickGUI::Label::Alignment::Left;
//	}
//};

//class Menu
//{
//	std::list<olc::QuickGUI::BaseControl*> uiElements;
//
//public:
//	olc::QuickGUI::Manager guiManager;
//
//	Menu()
//	{
//		for (auto& element : uiElements)
//		{
//			element = nullptr;
//		}
//	}
//
//	virtual void update(olc::PixelGameEngine* pge)
//	{
//		guiManager.Update(pge);
//	}
//
//	void addElement(olc::QuickGUI::BaseControl* element)
//	{
//		uiElements.push_back(element);
//	}
//};

class MenuManager;

class Menu
{
public:
	olc::PixelGameEngine* pge = nullptr;
	Client* client = nullptr;
	PlayerManager* playerManager = nullptr;
	MenuManager* menuManager = nullptr;

	olc::QuickGUI::Manager guiManager;

	Menu(olc::PixelGameEngine* _pge, PlayerManager* _playerManager, Client* _client, MenuManager* _menuManager);
	virtual void onNotify(Client* client, Event event) = 0;
	virtual void update();
	//virtual void update(olc::PixelGameEngine* pge, MenuManager* menuManager, Client* client);
};

class MainMenu : public Menu
{
	olc::QuickGUI::Label* titleLabel = nullptr;
	olc::QuickGUI::Button* startButton = nullptr;

public:
	MainMenu(olc::PixelGameEngine* _pge, PlayerManager* _playerManager, Client* _client, MenuManager* _menuManager);

	virtual void onNotify(Client* client, Event event) override;
	virtual void update() override;
};

class GameMenu : public Menu
{
	olc::QuickGUI::Button* joinButton = nullptr;
	olc::QuickGUI::Button* backButton = nullptr;
	olc::QuickGUI::Label* enterIpLabel = nullptr;
	olc::QuickGUI::TextBox* ipText = nullptr;
	olc::QuickGUI::TextBox* portText = nullptr;
	olc::QuickGUI::TextBox* nameText = nullptr;

	//Lobby
	std::vector<std::string> playerList;
	olc::QuickGUI::ListBox* playerListBox = nullptr;

public:
	GameMenu(olc::PixelGameEngine* _pge, PlayerManager* _playerManager, Client* _client, MenuManager* _menuManager);

	virtual void onNotify(Client* client, Event event) override;
	virtual void update() override;
};


class MenuManager : public Observer
{
	Menu* currentMenu = nullptr;

public:
	olc::PixelGameEngine* pge = nullptr;
	PlayerManager* playerManager = nullptr;
	Client* client = nullptr;

	MenuManager();

	void changeMenu(Menu* newMenu);

	virtual void onNotify(Client* client, Event event) override;

	void update();
	void draw();
};

#endif