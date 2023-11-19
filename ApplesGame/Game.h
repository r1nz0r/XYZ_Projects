#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Apple.h"
#include "Constants.h"
#include "Rock.h"

struct Game
{
	Player player;
	Apple apples[APPLES_AMOUNT];
	Rectangle rocks[ROCKS_AMOUNT];
	sf::Clock clock;
	sf::Font textFont;
	sf::Text scoreText;

	bool isGameFinished = false;
	int eatenApplesCount = 0;
};

void InitializeGame(Game& game);
void Restart(sf::RenderWindow& window, Game& game);
void InitializeGameScore(const sf::Font& textFont, Game& game);
void DrawGame(sf::RenderWindow& window, const Game& game);