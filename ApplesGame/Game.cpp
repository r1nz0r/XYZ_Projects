#include <cassert>
#include "Game.h"
#include "Rock.h"
#include "Player.h"

namespace ApplesGame
{
	void InitializeGame(Game& game)
	{
		game.textFont.loadFromFile(RESOURCES_PATH + FONT_NAME);

		assert(game.playerTexture.loadFromFile(RESOURCES_PATH + "Player.png"));
		assert(game.appleTexture.loadFromFile(RESOURCES_PATH + "Apple.png"));
		assert(game.rockTexture.loadFromFile(RESOURCES_PATH + "Rock.png"));
		assert(game.eatSoundBuffer.loadFromFile(RESOURCES_PATH + "AppleEat.wav"));
		assert(game.deathSoundBuffer.loadFromFile(RESOURCES_PATH + "Death.wav"));

		InitializePlayer(game.player, game);
		InitializeApples(game.apples, game);
		InitializeRocks(game.rocks, game);
		
		InitializeText(game.textFont, game.scoreText, game.scoreMessage, game.scoreTextPosition, game);
		InitializeText(game.textFont, game.hintText,game.hintMessage, game.hintTextPosition, game);
	}

	void DisplayDeathMessage(Game& game, sf::RenderWindow& window)
	{
		game.scoreText.setString("You loose! The game will restart in " + std::to_string(RESTART_DELAY) + " seconds");
		window.clear();
		window.draw(game.scoreText);
		window.display();
	}
	
	void Restart(Game& game)
	{
		InitializePlayer(game.player, game);
		InitializeApples(game.apples, game);
		game.eatenApplesCount = 0;
		game.scoreText.setString("Score: " + std::to_string(game.eatenApplesCount));
		game.pauseTimeLeft = RESTART_DELAY;
		game.isPaused = false;
	}

	void InitializeText(const sf::Font& textFont, sf::Text& text,
		std::string& message, const Position2D& location, Game& game)
	{
		text.setFont(textFont);
		text.setCharacterSize(15);
		text.setString(message);
		text.setPosition(location.x, location.y);
		text.setFillColor(sf::Color::Cyan);
	}


	void DrawGame(sf::RenderWindow& window, Game& game)
	{
		window.clear();
		DrawPlayer(game.player, window);
		
		for (Apple& apple : game.apples)
		{
			DrawApple(apple,window);
		}

		for (Rock& rock : game.rocks)
		{
			DrawRock(rock, window);
		}

		window.draw(game.scoreText);
		window.draw(game.hintText);
		window.display();
	}

	void InitializeShape(const Vector2D& object, const float size, const sf::Color& color, sf::Shape& shape)
	{
		shape.setFillColor(color);
		shape.setOrigin(size / 2.f, size / 2.f);
		shape.setPosition(object.x, object.y);
	}

	void PlaySound(Game& game, const sf::SoundBuffer& soundToPlay)
	{
		game.sound.setBuffer(soundToPlay);
		game.sound.play();
	}

	bool CheckPlayerCollisions(sf::RenderWindow& window, Game& game)
	{
		// Check bounds
		if (CheckBoundsCollision(game.player.position, game.player.SIZE))
		{
			PlaySound(game, game.deathSoundBuffer);
			return true;
		}

		for (int i = 0; i < APPLES_AMOUNT; ++i)
		{
			if (CheckSphereCollision(game.player.position, game.apples[i].position,
				game.player.SIZE, game.apples[i].SIZE))
			{
				SetRandomPosition(game.apples[i].position, SCREEN_WIDTH, SCREEN_HEIGHT);
				game.apples[i].sprite.setPosition(game.apples[i].position.x, game.apples[i].position.y);

				++game.eatenApplesCount;
				game.scoreText.setString("Score: " + std::to_string(game.eatenApplesCount));

				game.player.speed += game.player.ACCELERATION;
				PlaySound(game, game.eatSoundBuffer);
			}
		}

		for (int i = 0; i < ROCKS_AMOUNT; ++i)
		{
			if (CheckRectangleCollision(game.player.position, game.rocks[i].position,
				game.player.SIZE, game.rocks[i].SIZE))
			{
				PlaySound(game, game.deathSoundBuffer);
				return true;
			}			
		}

		return false;
	}
}
