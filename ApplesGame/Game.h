#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Apple.h"
#include "Rock.h"
#include "Constants.h"

namespace ApplesGame
{
    struct Game
    {
        Player player;
        Apple apples[APPLES_AMOUNT];
        Rock rocks[ROCKS_AMOUNT];        

        bool isGameFinished = false;
        int eatenApplesCount = 0;

        sf::Clock clock;
        sf::Font textFont;
        sf::Text scoreText;
        sf::Texture playerTexture;
    };

    void InitializeGame(Game& game);
    void Restart(sf::RenderWindow& window, Game& game);
    void InitializeGameScore(const sf::Font& textFont, Game& game);
    void DrawGame(sf::RenderWindow& window, const Game& game);
    void CheckPlayerCollisions(sf::RenderWindow& window, Game& game);
    void InitializeShape(const Vector2D& object, const float size, const sf::Color& color, sf::Shape& shape);
}
