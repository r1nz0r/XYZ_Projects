#pragma once
#include "CommonObjects.h"

enum class MoveDirection
{
    Right,
    Up,
    Left,
    Down,
    None
};

struct Player : public Rectangle
{
    const float ACCELERATION = 20.0f;
    const float INITIAL_SPEED = 100.0f;
    float speed = INITIAL_SPEED;
    MoveDirection direction = MoveDirection::None;
};

void InitializePlayer(Player& player);
void CalculatePlayerMovement(Player& player, const float deltaTime);