#include "Rock.h"
#include "Constants.h"
#include "Math.h"

void InitializeRocks(Rectangle rocks[])
{
	for (int i = 0; i < ROCKS_AMOUNT; ++i)
	{
		SetRandomObjectCoordinates(rocks[i], SCREEN_WIDTH, SCREEN_HEIGHT);
		rocks[i].shape.setSize(sf::Vector2f(rocks[i].SIZE, rocks[i].SIZE));

		InitializeShape(rocks[i], rocks[i].SIZE, sf::Color::Cyan, rocks[i].shape);
	}
}