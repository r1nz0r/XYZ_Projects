#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <vector>
#include "Player.h"
#include "Apple.h"
#include "Rock.h"
#include "Constants.h"
#include "UI.h"

namespace ApplesGame
{
    //GameMode
    const uint8_t FINITE_MODE = 0x01;
    const uint8_t ENDLESS_MODE = 0x02;
    const uint8_t ACCELERATION_MODE = 0x04;
    const uint8_t NO_ACCELERATION_MODE = 0x08;
    const size_t MENU_OPTIONS = 5;
    constexpr uint8_t DEFAULT_MODE = FINITE_MODE | ACCELERATION_MODE;

    struct Game
    {
        Player player;

        int applesAmount;
        std::vector<Apple> apples;

        int rocksAmount;
        std::vector<Rock> rocks;

        bool isStarted = false;
        bool isFinished = false;
        bool isPaused = false;
        bool isMuted = false;
        
        float pauseTimeLeft = RESTART_DELAY;

        int eatenApplesCount = 0;

        sf::Clock clock;
        Label menuLabels[MENU_OPTIONS];

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

        uint8_t mode = DEFAULT_MODE;
    };

    void InitializeMenu(Game& game);
    void ShowMenu(Game& game, sf::RenderWindow& window);
    void InitializeGame(Game& game);
    void Restart(Game& game);
    void DrawGame(sf::RenderWindow& window, Game& game);
    bool CheckPlayerCollisions(sf::RenderWindow& window, Game& game);
    void DisplayDeathMessage(Game& game, sf::RenderWindow& window);
    void InitializeShape(const Vector2D& object, const float size, const sf::Color& color, sf::Shape& shape);
    void PlaySound(Game& game, const sf::SoundBuffer& soundToPlay);
}
