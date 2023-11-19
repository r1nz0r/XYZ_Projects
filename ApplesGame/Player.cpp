#include "Player.h"
#include "Constants.h"

void InitializePlayer(Player& player)
{
    player.positionX = SCREEN_WIDTH / 2.0f;
    player.positionY = SCREEN_HEIGHT / 2.0f;
    player.speed = player.INITIAL_SPEED;
    player.direction = MoveDirection::None;
    player.shape.setSize(sf::Vector2f(player.SIZE, player.SIZE));

    InitializeShape(player, player.SIZE, sf::Color::Green, player.shape);
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
        deltaX = 1.f;
        break;
    case MoveDirection::Left:
        deltaX = -1.f;
        break;
    case MoveDirection::Down:
        deltaY = 1.f;
        break;
    case MoveDirection::Up:
        deltaY = -1.f;
        break;
    case MoveDirection::None:
    default:
        deltaX = 0.0f;
        deltaY = 0.0f;
        break;
    }

    player.positionX += deltaX * player.speed * deltaTime;
    player.positionY += deltaY * player.speed * deltaTime;
}
