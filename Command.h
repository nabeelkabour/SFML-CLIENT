#ifndef COMMAND_H
#define COMMAND_H

#include "Actor.h"
#include <iostream>

using std::cout;

class Command
{
public:
    virtual ~Command() {}
    virtual void execute(Actor* actor) = 0;
};

class MoveCommand : public Command
{
    //olc::vf2d positionNew;
    float posX;

public:
    //MoveCommand(olc::vf2d position) : positionNew(position) {}
    MoveCommand(float _x) : posX(_x) {}

    virtual void execute(Actor* actor)
    {
        actor->position.x = posX;
    }
};

class DamageCommand : public Command
{
public:
    virtual void execute(Actor* actor)
    {
        cout << "Damage Taken.\n";
        //actor->damage(); // Player* playerOne is passed.
    }
};

#endif