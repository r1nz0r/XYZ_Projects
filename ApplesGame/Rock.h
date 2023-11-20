#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"

struct Rock : Vector2D
{
    const float SIZE = 15.0f;
    sf::RectangleShape shape;
};

void InitializeRocks(Rock rocks[]);