#include <cassert>
#include <random>
#include "Game.h"
#include "Rock.h"
#include "Player.h"

namespace ApplesGame
{
    void ShowMenu(Game& game, sf::RenderWindow& window)
    {
        window.clear();

        for (auto& menuLabel : game.menuLabels)
            window.draw(menuLabel.text);
    }

    void InitializeMenu(Game& game)
    {
        game.menuLabels[0].message = "1. Finite game mode";
        game.menuLabels[0].color = sf::Color::Green;

        game.menuLabels[1].message = "2. Endless game mode";
        game.menuLabels[1].color = sf::Color::Yellow;

        game.menuLabels[2].message = "3. Acceleration game mode";
        game.menuLabels[2].color = sf::Color::Green;

        game.menuLabels[3].message = "4. Standart speed game mode";
        game.menuLabels[3].color = sf::Color::Yellow;

        game.menuLabels[4].message = "Enter - Start game";
        game.menuLabels[4].color = sf::Color::Cyan;

        for (int i = 0; i < MENU_OPTIONS; ++i)
        {
            game.menuLabels[i].position = {10.0f, (i + 1) * 15.0f};
            InitializeLabel(game.menuLabels[i]);
        }
    }

    void InitializeGame(Game& game)
    {
        game.applesAmount = GetRandomInt(APPLES_AMOUNT_MIN, APPLES_AMOUNT_MAX);
        game.rocksAmount = GetRandomInt(ROCKS_AMOUNT_MIN, ROCKS_AMOUNT_MAX);

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
        InitializeLabel(game.scoreLabel);
        game.hintLabel.position = {10, 30};
        game.hintLabel.message = "Use arrows to move pacman.\nEat apples, dont touch borders and rocks."
            "\nFor toggle sound press \"M\" key"
            "\nFor toggle hint message visibility press \"H\" key";
        InitializeLabel(game.hintLabel);
    }

    void DisplayDeathMessage(Game& game, sf::RenderWindow& window)
    {
        game.scoreLabel.text.setString(
            "You loose! The game will restart in " + std::to_string(RESTART_DELAY) + " seconds" +
            "\nYour score is: " + std::to_string(game.eatenApplesCount));
        window.clear();
        window.draw(game.scoreLabel.text);
        window.display();
    }

    void Restart(Game& game)
    {
        InitializePlayer(game.player, game);
        InitializeApples(game.apples, game);
        game.isStarted = false;
        game.eatenApplesCount = 0;
        game.scoreLabel.text.setString("Score: " + std::to_string(game.eatenApplesCount));
        game.pauseTimeLeft = RESTART_DELAY;
        game.isPaused = false;
    }

    void DrawGame(sf::RenderWindow& window, Game& game)
    {
        window.clear();
        DrawPlayer(game.player, window);

        for (Apple& apple : game.apples)
        {
            if (apple.isEaten == false)
                DrawApple(apple, window);
        }

        for (Rock& rock : game.rocks)
        {
            DrawRock(rock, window);
        }

        window.draw(game.scoreLabel.text);

        if (game.hintLabel.isVisible)
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

    void OnAppleCollisionEnter(Game& game, Apple& apple)
    {
        if (game.mode & ENDLESS_MODE)
        {
            SetRandomPosition(apple.position, SCREEN_WIDTH, SCREEN_HEIGHT);
            apple.sprite.setPosition(apple.position.x, apple.position.y);
        }
        else
        {
            apple.isEaten = true;
        }

        ++game.eatenApplesCount;
        game.scoreLabel.text.setString("Score: " + std::to_string(game.eatenApplesCount));

        if (game.mode & ACCELERATION_MODE)
            game.player.speed += game.player.ACCELERATION;

        if (!game.isMuted)
            PlaySound(game, game.eatSoundBuffer);
    }

    bool CheckPlayerCollisions(sf::RenderWindow& window, Game& game)
    {
        // Check bounds
        if (CheckBoundsCollision(game.player.position, game.player.SIZE))
        {
            if (!game.isMuted)
                PlaySound(game, game.deathSoundBuffer);
            
            return true;
        }

        for (int i = 0; i < game.applesAmount; ++i)
        {
            if (game.apples[i].isEaten)
                continue;

            if (CheckSphereCollision(game.player.position, game.apples[i].position,
                                     game.player.SIZE, game.apples[i].SIZE))
            {
                OnAppleCollisionEnter(game, game.apples[i]);
            }
        }

        for (int i = 0; i < game.rocksAmount; ++i)
        {
            if (CheckRectangleCollision(game.player.position, game.rocks[i].position,
                                        game.player.SIZE, game.rocks[i].SIZE))
            {
                if (!game.isMuted)
                    PlaySound(game, game.deathSoundBuffer);
                
                return true;
            }
        }

        return false;
    }
}
