#pragma once
#include "SFML/Graphics.hpp"
#include "Math.h"

enum class MoveDirection
{
    Right,
    Up,
    Left,
    Down,
    None
};

struct Player : Vector2D
{
    const float ACCELERATION = 20.0f;
    const float INITIAL_SPEED = 100.0f;
    const float SIZE = 20.0f;
    float speed = INITIAL_SPEED;
    sf::RectangleShape shape;
    MoveDirection direction = MoveDirection::None;
};

void InitializePlayer(Player& player);
void CalculatePlayerMovement(Player& player, const float deltaTime);