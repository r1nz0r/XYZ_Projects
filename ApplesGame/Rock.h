#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"

namespace ApplesGame
{
    struct Game;
    
    struct Rock
    {
        Position2D position;
        const float SIZE = 20.0f;
        sf::Sprite sprite;
    };
    
    void InitializeRocks(Rock rocks[], const Game& game);
    void DrawRock(Rock& rock, sf::RenderWindow& window);

}