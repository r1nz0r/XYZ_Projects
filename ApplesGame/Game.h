#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Apple.h"
#include "Rock.h"
#include "Constants.h"
#include "SFML/Audio/Sound.hpp"
#include "SFML/Audio/SoundBuffer.hpp"

namespace ApplesGame
{
    struct Game
    {
        Player player;
        Apple apples[APPLES_AMOUNT];
        Rock rocks[ROCKS_AMOUNT];        

        bool isFinished = false;
        bool isPaused = false;
        float pauseTimeLeft = RESTART_DELAY;
        
        int eatenApplesCount = 0;

        sf::Clock clock;
        sf::Font textFont;

        Position2D scoreTextPosition = {10, 10};
        std::string scoreMessage = "Score: " + std::to_string(eatenApplesCount);
        sf::Text scoreText;
        Position2D hintTextPosition = {10,30};
        std::string hintMessage = "Use arrows to move pacman.\nEat apples, dont touch borders and rocks.";
        sf::Text hintText;

        //Textures
        sf::Texture playerTexture;
        sf::Texture appleTexture;
        sf::Texture rockTexture;

        //Audio
        sf::SoundBuffer eatSoundBuffer;
        sf::SoundBuffer deathSoundBuffer;
        sf::Sound sound;
    };

    void InitializeGame(Game& game);
    void Restart(Game& game);
    void InitializeText(const sf::Font& textFont, sf::Text& text,
       std::string& message, const Position2D& location, Game& game);
    void DrawGame(sf::RenderWindow& window, Game& game);
    bool CheckPlayerCollisions(sf::RenderWindow& window, Game& game);
    void DisplayDeathMessage(Game& game, sf::RenderWindow& window);
    void InitializeShape(const Vector2D& object, const float size, const sf::Color& color, sf::Shape& shape);
	void PlaySound(Game& game, const sf::SoundBuffer& soundToPlay);

}
