#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"

namespace ApplesGame
{
    struct Rock
    {
        Position2D position;
        const float SIZE = 20.0f;
        sf::RectangleShape shape;
    };
    
    void InitializeRocks(Rock rocks[]);
}