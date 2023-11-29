#include "Rock.h"
#include "Constants.h"
#include "Math.h"
#include "Game.h"

namespace ApplesGame
{
	void InitializeRocks(std::vector<Rock>& rocks, const Game& game)
	{
		rocks.resize(game.rocksAmount);
		
		for (int i = 0; i < game.rocksAmount; ++i)
		{
			SetRandomPosition(rocks[i].position, SCREEN_WIDTH, SCREEN_HEIGHT);
			rocks[i].sprite.setTexture(game.rockTexture);
			rocks[i].size = Vector2D(20.0f, 20.0f);
			
			SetSpriteSize(rocks[i].sprite, rocks[i].size.x, rocks[i].size.y);
			SetSpriteRelativeOrigin(rocks[i].sprite, 0.5f, 0.5f);
		}
	}

	void DrawRock(Rock& rock, sf::RenderWindow& window)
	{
		rock.sprite.setPosition(rock.position.x, rock.position.y);
		window.draw(rock.sprite);
	}
}