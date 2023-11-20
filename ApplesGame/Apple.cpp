#include "Apple.h"
#include "Constants.h"
#include "Math.h"

namespace ApplesGame
{
	void InitializeApples(Apple apples[])
	{
		for (int i = 0; i < APPLES_AMOUNT; ++i)
		{
			SetRandomPosition(apples[i], SCREEN_WIDTH, SCREEN_HEIGHT);
			apples[i].shape.setRadius(apples[i].SIZE / 2.0f);

			InitializeShape(apples[i], apples[i].SIZE, sf::Color::Red, apples[i].shape);
		}
	}
}