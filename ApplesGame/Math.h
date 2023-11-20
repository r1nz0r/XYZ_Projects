#pragma once
#include "Game.h"
#include "Rock.h"

namespace ApplesGame
{      
    bool CheckAppleAndPlayerCollision(const Player& player, const Apple& apple);
    bool CheckRocksAndPlayerCollision(const Player& player, const Rock rocks[]);
    bool CheckBoundsCollision(const Game& game);
    void CheckPlayerCollisions(sf::RenderWindow& window, Game& game);
}