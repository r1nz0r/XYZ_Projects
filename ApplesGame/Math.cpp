#include "Math.h"
#include "Apple.h"

void SetRandomObjectCoordinates(Vector2D& object, float screenWidth, float screenHeight)
{
	object.positionX = rand() / static_cast<float>(RAND_MAX) * screenWidth;
	object.positionY = rand() / static_cast<float>(RAND_MAX) * screenHeight;
}

bool CheckAppleAndPlayerCollision(const Player& player, const Apple& apple)
{
	for (int i = 0; i < APPLES_AMOUNT; ++i)
	{
		//Check circles:
		float squareDistance = (player.positionX - apple.positionX) * (player.positionX - apple.positionX) +
			(player.positionY - apple.positionY) * (player.positionY - apple.positionY);
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
		if (fabs(player.positionX - rocks[i].positionX) <= (player.SIZE + rocks[i].SIZE) / 2.0f &&
			fabs(player.positionY - rocks[i].positionY) <= (player.SIZE + rocks[i].SIZE) / 2.0f)
		{
			return true;
		}
	}

	return false;
}

bool CheckBoundsCollision(const Game& game)
{
	if (game.player.positionX - game.player.SIZE / 2.f <= 0 ||
		game.player.positionX + game.player.SIZE / 2.f >= SCREEN_WIDTH ||
		game.player.positionY - game.player.SIZE / 2.f <= 0 ||
		game.player.positionY + game.player.SIZE / 2.f >= SCREEN_HEIGHT)
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
			SetRandomObjectCoordinates(game.apples[i], SCREEN_WIDTH, SCREEN_HEIGHT);
			game.apples[i].shape.setPosition(game.apples[i].positionX, game.apples[i].positionY);

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

void InitializeShape(const Vector2D& object, const float size, const sf::Color& color, sf::Shape& shape)
{
	shape.setFillColor(color);
	shape.setOrigin(size / 2.f, size / 2.f);
	shape.setPosition(object.positionX, object.positionY);
}