#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"

struct Apple : Vector2D
{
	const float SIZE = 10.0f;
	sf::CircleShape shape;
};

void InitializeApples(Apple apples[]);