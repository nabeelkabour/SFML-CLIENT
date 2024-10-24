#include "Observer.h"

void Subject::notify(sf::Packet packet)
{
	for (auto _observer : _observers)
	{
		_observer->onNotify(packet);
	}
}

void Subject::addObserver(Observer* observer)
{
	_observers.push_back(observer);
}

void Subject::removeObserver(Observer* observer)
{
	for (uint16_t i = 0; i < _observers.size(); ++i)
	{
		if (observer == _observers[i])
		{
			_observers.erase(_observers.begin() + i);
			break;
		}
	}
}