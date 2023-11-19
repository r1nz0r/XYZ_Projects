// ©2023, XYZ School. All rights reserved.
// Authored by Aleksandr Rybalka (polterageist@gmail.com)

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Constants.h"
#include "Player.h"
#include "Apple.h"
#include "Math.h"
#include "Rock.h"
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), GAME_TITLE);

	srand(static_cast<unsigned>(time(nullptr)));

	Game game;
	InitializeGame(game);

	float lastTime = game.clock.getElapsedTime().asSeconds();

	sf::Font textFont;
	textFont.loadFromFile(RESOURCES_PATH + FONT_NAME);

	InitializeGameScore(textFont, game);

	while (window.isOpen())
	{
		//Calculate delta time
		float currentTime = game.clock.getElapsedTime().asSeconds();
		float deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		//Read events
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
		}

		CalculatePlayerMovement(game.player, deltaTime);
		CheckPlayerCollisions(window, game);

		game.player.shape.setPosition(game.player.positionX, game.player.positionY);

		DrawGame(window, game);
	}

	return 0;
}