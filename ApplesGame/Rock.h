#pragma once
#include "Vector2D.h"

namespace ApplesGame
{
    struct Rock : public Vector2D
    {
        const float SIZE = 20.0f;
        sf::RectangleShape shape;
    };
    
    void InitializeRocks(Rock rocks[]);
}