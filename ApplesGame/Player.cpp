#include "Player.h"
#include "Constants.h"
#include "Game.h"

namespace ApplesGame
{
    void InitializePlayer(Player& player, const Game& game)
    {
        player.position.x = SCREEN_WIDTH / 2.0f;
        player.position.y = SCREEN_HEIGHT / 2.0f;
        player.speed = player.INITIAL_SPEED;
        player.direction = MoveDirection::None;
        //player.shape.setSize(sf::Vector2f(player.SIZE, player.SIZE));
        //InitializeShape(player.position, player.SIZE, sf::Color::Green, player.shape);
        player.sprite.setTexture(game.playerTexture);
        SetSpriteSize(player.sprite, player.SIZE, player.SIZE);
        SetSpriteRelativeOrigin(player.sprite, 0.5f, 0.5f);
    }

    void CalculatePlayerMovement(Player& player, const float deltaTime)
    {
        //Player movement calculation
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            player.direction = MoveDirection::Right;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            player.direction = MoveDirection::Up;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            player.direction = MoveDirection::Left;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            player.direction = MoveDirection::Down;

        float deltaX = 0, deltaY = 0;

        switch (player.direction)
        {
        case MoveDirection::Right:
            {
                deltaX = 1.f;
                player.sprite.setRotation(ANGLE_LOOK_RIGHT);
                break;
            }
        case MoveDirection::Left:
            {
                deltaX = -1.f;
                player.sprite.setRotation(ANGLE_LOOK_LEFT);
                break;
            }
        case MoveDirection::Down:
            {
                deltaY = 1.f;
                player.sprite.setRotation(ANGLE_LOOK_DOWN);
                break;
            }
        case MoveDirection::Up:
            {
                deltaY = -1.f;
                player.sprite.setRotation(ANGLE_LOOK_UP);
                break;
            }
        case MoveDirection::None:
            deltaX = 0.0f;
            deltaY = 0.0f;
            break;
        }

        player.position.x += deltaX * player.speed * deltaTime;
        player.position.y += deltaY * player.speed * deltaTime;
    }

    void DrawPlayer(Player& player, sf::RenderWindow& window)
    {
        player.sprite.setPosition(player.position.x, player.position.y);
        window.draw(player.sprite);
    }
}
