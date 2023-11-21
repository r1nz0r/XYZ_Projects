#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"

namespace ApplesGame
{
	struct Game;
	
	struct Apple
	{
		const float SIZE = 20.0f;
		Position2D position;
		sf::Sprite sprite;
	};

	void InitializeApples(Apple apples[], const Game& game);
	void DrawApple(Apple& apple, sf::RenderWindow& window);

}