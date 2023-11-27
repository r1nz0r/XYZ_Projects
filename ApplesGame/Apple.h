#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Math.h"

namespace ApplesGame
{
	struct Game;
	
	struct Apple
	{
		const float SIZE = 20.0f;
		bool isEaten = false;
		Position2D position;
		sf::Sprite sprite;
	};

	void InitializeApples(std::vector<Apple>& apples, const Game& game);
	void DrawApple(Apple& apple, sf::RenderWindow& window);

}