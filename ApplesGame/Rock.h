#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Math.h"

namespace ApplesGame
{
    struct Game;

    struct Rock : Rectangle
    {
        sf::Sprite sprite;
    };

    void InitializeRocks(std::vector<Rock>& rocks, const Game& game);
    void SetRockPosition(Rock& rock);
    void DrawRock(const Rock& rock, sf::RenderWindow& window);
}
