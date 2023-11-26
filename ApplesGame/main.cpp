// ©2023, XYZ School. All rights reserved.
// Authored by Aleksandr Rybalka (polterageist@gmail.com)

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Constants.h"
#include "Player.h"
#include "Game.h"

using namespace ApplesGame;

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), GAME_TITLE);

    srand(static_cast<unsigned>(time(nullptr)));

    Game game;
    InitializeGame(game);

    float lastTime = game.clock.getElapsedTime().asSeconds();

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
        
        if (game.isPaused == false)
        {
            CalculatePlayerMovement(game.player, deltaTime);
            RotatePlayer(game.player);
            game.isPaused = CheckPlayerCollisions(window, game);
            DrawGame(window, game);
        }
        else
        {
            game.pauseTimeLeft -= deltaTime;
            DisplayDeathMessage(game, window);
            if (game.pauseTimeLeft <= 0.0f)
            {
                Restart(game);
            }
        }
    }

    return 0;
}
