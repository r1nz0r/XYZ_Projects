#include "Rock.h"
#include "Constants.h"
#include "Math.h"
#include "Game.h"

namespace ApplesGame
{
	void InitializeRocks(Rock rocks[], const Game& game)
	{
		for (int i = 0; i < ROCKS_AMOUNT; ++i)
		{
			SetRandomPosition(rocks[i].position, SCREEN_WIDTH, SCREEN_HEIGHT);
			rocks[i].sprite.setTexture(game.rockTexture);

			SetSpriteSize(rocks[i].sprite, rocks[i].SIZE, rocks[i].SIZE);
			SetSpriteRelativeOrigin(rocks[i].sprite, 0.5f, 0.5f);
		}
	}

	void DrawRock(Rock& rock, sf::RenderWindow& window)
	{
		rock.sprite.setPosition(rock.position.x, rock.position.y);
		window.draw(rock.sprite);
	}
}