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
		
		game.scoreLabel.position = {10, 10};
		game.scoreLabel.message = "Score: " + std::to_string(game.eatenApplesCount);
		InitializeLabel(game.textFont, game.scoreLabel);
		
		game.hintLabel.position = {10, 30};
		game.hintLabel.message = "Use arrows to move pacman.\nEat apples, dont touch borders and rocks.";
		InitializeLabel(game.textFont, game.hintLabel);
	}

	void DisplayDeathMessage(Game& game, sf::RenderWindow& window)
	{
		game.scoreLabel.text.setString("You loose! The game will restart in " + std::to_string(RESTART_DELAY) + " seconds");
		window.clear();
		window.draw(game.scoreLabel.text);
		window.display();
	}
	
	void Restart(Game& game)
	{
		InitializePlayer(game.player, game);
		InitializeApples(game.apples, game);
		game.eatenApplesCount = 0;
		game.scoreLabel.text.setString("Score: " + std::to_string(game.eatenApplesCount));
		game.pauseTimeLeft = RESTART_DELAY;
		game.isPaused = false;
	}

	void InitializeLabel(const sf::Font& textFont, Label& label)
	{
		label.text.setFont(textFont);
		label.text.setCharacterSize(15);
		label.text.setString(label.message);
		label.text.setPosition(label.position.x, label.position.y);
		label.text.setFillColor(sf::Color::Cyan);
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

		window.draw(game.scoreLabel.text);
		window.draw(game.hintLabel.text);
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
				game.scoreLabel.text.setString("Score: " + std::to_string(game.eatenApplesCount));

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
