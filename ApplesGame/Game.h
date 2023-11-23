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
    struct Label
    {
        Position2D position;
        std::string message;
        sf::Text text;
    };
    
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

        Label scoreLabel;
        Label hintLabel;
        
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
    void InitializeLabel(const sf::Font& textFont, Label& game);
    void DrawGame(sf::RenderWindow& window, Game& game);
    bool CheckPlayerCollisions(sf::RenderWindow& window, Game& game);
    void DisplayDeathMessage(Game& game, sf::RenderWindow& window);
    void InitializeShape(const Vector2D& object, const float size, const sf::Color& color, sf::Shape& shape);
	void PlaySound(Game& game, const sf::SoundBuffer& soundToPlay);

}
