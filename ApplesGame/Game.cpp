#include "Game.h"

void InitializeGame(Game& game)
{
	InitializePlayer(game.player);
	InitializeApples(game.apples);
	InitializeRocks(game.rocks);
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

	for (const Rectangle& rock : game.rocks)
	{
		window.draw(rock.shape);
	}

	window.draw(game.scoreText);
	window.display();
}