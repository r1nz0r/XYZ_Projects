#include "Rock.h"
#include "Constants.h"
#include "Math.h"
#include "Game.h"

namespace ApplesGame
{
	void InitializeRocks(Rock rocks[])
	{
		for (int i = 0; i < ROCKS_AMOUNT; ++i)
		{
			SetRandomPosition(rocks[i].position, SCREEN_WIDTH, SCREEN_HEIGHT);
			rocks[i].shape.setSize(sf::Vector2f(rocks[i].SIZE, rocks[i].SIZE));

			InitializeShape(rocks[i].position, rocks[i].SIZE, sf::Color::Cyan, rocks[i].shape);
		}
	}
}