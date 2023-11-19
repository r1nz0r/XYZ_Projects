#pragma once
#include <SFML/Graphics.hpp>
#include "CommonObjects.h"

struct Apple : public Object
{
	sf::CircleShape shape;
};

void InitializeApples(Apple apples[]);