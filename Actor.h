#ifndef ACTOR_H
#define ACTOR_H

#include "olcUTIL_Geometry2D.h"
//#include "ManifestedEntity.h"
#include "Entity.h"
#include <cstdint>
#include <string>

//Actors are anything drawn on the screen that collide with each other.
class Actor : public Entity
{
public:
    olc::vf2d position = { 0.f, 0.f };
    circle<float> collisionMask = circle<float>(position, 10.f);

    Actor() {}
    Actor(float _x, float _y) :  position(_x, _y) {}
    Actor(olc::vf2d pos) : position(pos) {}
};

//class Circle : public Actor
//{
//public:
//    Circle(int32_t _x, int32_t _y) : x(_x), y(_y) {}
//};

#endif