#include <cassert>
#include "Game.h"
#include "Rock.h"

namespace ApplesGame
{
	void InitializeGame(Game& game)
	{
		game.textFont.loadFromFile(RESOURCES_PATH + FONT_NAME);

		//assert(game.playerTexture.loadFromFile(RESOURCES_PATH + "/Player.png"));
		
		InitializePlayer(game.player);
		InitializeApples(game.apples);
		InitializeRocks(game.rocks);
		InitializeGameScore(game.textFont, game);
	}

	void Restart(sf::RenderWindow& window, Game& game)
	{
		game.scoreText.setString("You loose! The game will restart in " + std::to_string(RESTART_DELAY) + " seconds");
		window.clear();
		window.draw(game.scoreText);
		window.display();
		sf::sleep(sf::Time(sf::seconds(RESTART_DELAY)));
		InitializePlayer(game.player);
		InitializeApples(game.apples);
		game.scoreText.setString("Score: " + std::to_string(game.eatenApplesCount));
	}

	void InitializeGameScore(const sf::Font& textFont, Game& game)
	{
		game.scoreText.setFont(textFont);
		game.scoreText.setCharacterSize(20);
		game.scoreText.setString("Score: " + std::to_string(game.eatenApplesCount));
		game.scoreText.setPosition(10.0f, 10.0f);
		game.scoreText.setFillColor(sf::Color::Yellow);
	}

	void DrawGame(sf::RenderWindow& window, const Game& game)
	{
		window.clear();
		window.draw(game.player.shape);

		for (const Apple& apple : game.apples)
		{
			window.draw(apple.shape);
		}

		for (const Rock& rock : game.rocks)
		{
			window.draw(rock.shape);
		}

		window.draw(game.scoreText);
		window.display();
	}

	void InitializeShape(const Vector2D& object, const float size, const sf::Color& color, sf::Shape& shape)
	{
		shape.setFillColor(color);
		shape.setOrigin(size / 2.f, size / 2.f);
		shape.setPosition(object.x, object.y);
	}
	
	void CheckPlayerCollisions(sf::RenderWindow& window, Game& game)
	{
		// Check bounds
		if (CheckBoundsCollision(game.player.position, game.player.SIZE))
			Restart(window, game);

		for (int i = 0; i < APPLES_AMOUNT; ++i)
		{
			if (CheckSphereCollision(game.player.position, game.apples[i].position,
				game.player.SIZE, game.apples[i].SIZE))
			{
				SetRandomPosition(game.apples[i].position, SCREEN_WIDTH, SCREEN_HEIGHT);
				game.apples[i].shape.setPosition(game.apples[i].position.x, game.apples[i].position.y);

				++game.eatenApplesCount;
				game.scoreText.setString("Score: " + std::to_string(game.eatenApplesCount));

				game.player.speed += game.player.ACCELERATION;
			}
		}

		for (int i = 0; i < ROCKS_AMOUNT; ++i)
		{
			if (CheckRectangleCollision(game.player.position, game.rocks[i].position,
				game.player.SIZE, game.rocks[i].SIZE))
			{
				Restart(window, game);
			}			
		}
	}
}
