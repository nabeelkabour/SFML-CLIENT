#include "olcPixelGameEngine.h"
#include "olcUTIL_Geometry2D.h"
#include "Player.h"

Player::Player(int8_t _playerId)
{
	playerData.playerId = _playerId;
}

Player::Player(int8_t _playerId, float _x, float _y) : Actor(_x, _y)
{
	playerData.playerId = _playerId;
}

Player::Player(int8_t _playerId, olc::vf2d pos) : Actor(pos)
{
	playerData.playerId = _playerId;
}

bool Player::collidesWith(Actor* other)
{
	return overlaps(collisionMask, other->collisionMask);
}