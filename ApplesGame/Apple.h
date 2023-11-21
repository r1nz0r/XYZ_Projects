#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"

namespace ApplesGame
{
	struct Apple
	{
		const float SIZE = 20.0f;
		Position2D position;
		sf::CircleShape shape;
	};

	void InitializeApples(Apple apples[]);
}