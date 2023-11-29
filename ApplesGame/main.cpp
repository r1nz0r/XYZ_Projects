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
    InitializeMenu(game);
    InitializeGame(game);

    float lastTime = game.clock.getElapsedTime().asSeconds();

    while (window.isOpen())
    {
        //Read events
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                window.close();

            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::H))
                game.hintLabel.isVisible = !game.hintLabel.isVisible;

            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Enter))
                game.isStarted = true;

            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::M))
                game.isMuted = !game.isMuted;
        }

        if (game.isStarted)
        {
            //Calculate delta time
            float currentTime = game.clock.getElapsedTime().asSeconds();
            float deltaTime = currentTime - lastTime;
            //float deltaTime = 0.0005f;
            lastTime = currentTime;

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
                std::string endMessage;

                if (game.applesAmount != game.eatenApplesCount)
                {
                    endMessage = "You loose! The game will restart in " + std::to_string(RESTART_DELAY) + " seconds" +
                    "\nYour score is: " + std::to_string(game.eatenApplesCount); 
                }
                else
                {
                    endMessage = "You Win! The game will restart in " + std::to_string(RESTART_DELAY) + " seconds" +
                    "\nYour score is: " + std::to_string(game.eatenApplesCount); 
                }
                
                DisplayEndMessage(game, endMessage, window);
                
                if (game.pauseTimeLeft <= 0.0f)
                {
                    Restart(game);
                }
            }
        }
        else
        {
            ShowMenu(game, window);
            window.display();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
            {
                game.menuLabels[0].text.setFillColor(sf::Color::Green);
                game.menuLabels[1].text.setFillColor(sf::Color::Yellow);
                game.mode |= FINITE_MODE;
                game.mode &= ~ENDLESS_MODE;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
            {
                game.menuLabels[0].text.setFillColor(sf::Color::Yellow);
                game.menuLabels[1].text.setFillColor(sf::Color::Green);
                game.mode |= ENDLESS_MODE;
                game.mode &= ~FINITE_MODE;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
            {
                game.menuLabels[2].text.setFillColor(sf::Color::Green);
                game.menuLabels[3].text.setFillColor(sf::Color::Yellow);
                game.mode |= ACCELERATION_MODE;
                game.mode &= ~NO_ACCELERATION_MODE;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
            {
                game.menuLabels[2].text.setFillColor(sf::Color::Yellow);
                game.menuLabels[3].text.setFillColor(sf::Color::Green);
                game.mode |= NO_ACCELERATION_MODE;
                game.mode &= ~ACCELERATION_MODE;
            }
        }
    }

    return 0;
}
