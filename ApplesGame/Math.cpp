#include "Math.h"

namespace ApplesGame
{
	bool CheckAppleAndPlayerCollision(const Player& player, const Apple& apple)
	{
		for (int i = 0; i < APPLES_AMOUNT; ++i)
		{
			//Check circles:
			float squareDistance = (player.x - apple.x) * (player.x - apple.x) +
				(player.y - apple.y) * (player.y - apple.y);
			float squareRadiusSum = (apple.SIZE + player.SIZE) * (apple.SIZE + player.SIZE) / 4;

			if (squareDistance <= squareRadiusSum)
			{
				return true;
			}
		}

		return false;
	}

	bool CheckRocksAndPlayerCollision(const Player& player, const Rock rocks[])
	{
		for (int i = 0; i < ROCKS_AMOUNT; ++i)
		{
			if (fabs(player.y - rocks[i].x) <= (player.SIZE + rocks[i].SIZE) / 2.0f &&
				fabs(player.y - rocks[i].y) <= (player.SIZE + rocks[i].SIZE) / 2.0f)
			{
				return true;
			}
		}

		return false;
	}

	bool CheckBoundsCollision(const Game& game)
	{
		if (game.player.x - game.player.SIZE / 2.f <= 0 ||
			game.player.x + game.player.SIZE / 2.f >= SCREEN_WIDTH ||
			game.player.y - game.player.SIZE / 2.f <= 0 ||
			game.player.y + game.player.SIZE / 2.f >= SCREEN_HEIGHT)
		{
			return true;
		}

		return false;
	}

	void CheckPlayerCollisions(sf::RenderWindow& window, Game& game)
	{
		// Check bounds
		if (CheckBoundsCollision(game))
			Restart(window, game);

		for (int i = 0; i < APPLES_AMOUNT; ++i)
		{
			if (CheckAppleAndPlayerCollision(game.player, game.apples[i]))
			{
				SetRandomPosition(game.apples[i], SCREEN_WIDTH, SCREEN_HEIGHT);
				game.apples[i].shape.setPosition(game.apples[i].x, game.apples[i].y);

				++game.eatenApplesCount;
				game.scoreText.setString("Score: " + std::to_string(game.eatenApplesCount));

				game.player.speed += game.player.ACCELERATION;
			}
		}

		if (CheckRocksAndPlayerCollision(game.player, game.rocks))
		{
			Restart(window, game);
		}
	}
}