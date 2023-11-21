#include "Apple.h"
#include "Constants.h"
#include "Math.h"
#include "Game.h"

namespace ApplesGame
{
	void InitializeApples(Apple apples[], const Game& game)
	{
		for (int i = 0; i < APPLES_AMOUNT; ++i)
		{
			SetRandomPosition(apples[i].position, SCREEN_WIDTH, SCREEN_HEIGHT);
			apples[i].sprite.setTexture(game.appleTexture);
			SetSpriteSize(apples[i].sprite, apples[i].SIZE, apples[i].SIZE);
			SetSpriteRelativeOrigin(apples[i].sprite, 0.5f, 0.5f);
		}
	}

	void DrawApple(Apple& apple, sf::RenderWindow& window)
	{
		apple.sprite.setPosition(apple.position.x, apple.position.y);
		window.draw(apple.sprite);
	}
}