#ifndef PLAYER_H
#define PLAYER_H

#include "olcUTIL_Geometry2D.h"
#include "Actor.h"

struct PlayerData
{
	std::string name = "NONE";
	int8_t playerId = -1;
	int32_t hp = 100;
};

class Player : public Actor
{
public:
	PlayerData playerData;

	Player(int8_t _playerId);
	Player(int8_t _playerId, float _x, float _y);
	Player(int8_t _playerId, olc::vf2d pos);

	bool collidesWith(Actor* other);
};

class OtherPlayer : Actor
{
public:
	PlayerData playerData;

	OtherPlayer(int8_t _playerId)
	{
		playerData.playerId = _playerId;
	}

	OtherPlayer(int8_t _playerId, float _x, float _y) : Actor(_x, _y)
	{
		playerData.playerId = _playerId;
	}

	OtherPlayer(int8_t _playerId, olc::vf2d pos) : Actor(pos)
	{
		playerData.playerId = _playerId;
	}
};


//class Player : public Actor //,public Subject
//{
//	std::string name = "Player";
//	int32_t hp = 100;
//
//public:
//	int32_t playerId = -1;
//
//	Player(int32_t _playerId) : playerId(_playerId) {}
//	Player(float _x, float _y) : Actor(_x, _y) {}
//	Player(olc::vf2d pos) : Actor(pos) {}
//
//	bool collidesWith(Actor* other)
//	{
//		return overlaps(collisionMask, other->collisionMask);
//	}
//
//	void damage(uint32_t _dmg)
//	{
//		hp -= _dmg;
//
//		//notify(*this, Event::DAMAGE);
//	}
//};

#endif