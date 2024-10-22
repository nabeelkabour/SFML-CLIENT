#ifndef OBSERVER_H
#define OBSERVER_H

#include "SFML/Network.hpp"
#include <cstdint>
#include "Entity.h"
#include <iostream>
#include <vector>

//enum class Event : uint16_t
//{
//	NONE,
//	DAMAGE,
//	FIRST_BLOOD,
//
//	CLIENT_CONNECTED,
//	CLIENT_BROADCAST,
//	CLIENT_SYNC,
//	CLIENT_NAME
//};

class Client;

class Observer
{
public:
	virtual ~Observer() {}
	virtual void onNotify(sf::Packet packet) = 0;
	//virtual void onNotify(Event event, int32_t data) = 0;
};

class Subject
{
	std::vector<Observer*> _observers;

protected:
	void notify(sf::Packet packet);

public:
	void addObserver(Observer* observer);
	void removeObserver(Observer* observer);
};

//class Announcements : public Observer
//{
//	bool firstBlood = false;
//
//public:
//	virtual void onNotify(const Entity& entity, Event event)
//	{
//		switch (event)
//		{
//		case Event::DAMAGE:
//		{
//			if (!firstBlood)
//			{
//				std::cout << "First Blood!\n" << entity.name;
//				firstBlood = true;
//			}
//		}
//		break;
//		}
//	}
//};

#endif