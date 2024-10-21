#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "Networking.h"
#include "Game.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;      


int main()
{
    Game gameClient;

    if (gameClient.Construct(SCREENWIDTH, SCREENHEIGHT, 2, 2))
        gameClient.Start();

    return 0;
}
