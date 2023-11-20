#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2D.h"

namespace ApplesGame
{
	struct Apple : public Vector2D
	{
		const float SIZE = 20.0f;
		sf::CircleShape shape;
	};

	void InitializeApples(Apple apples[]);
}