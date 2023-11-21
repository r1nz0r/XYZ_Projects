#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"

namespace ApplesGame
{
    enum class MoveDirection
    {
        Right,
        Up,
        Left,
        Down,
        None
    };
    
    struct Player
    {
        const float SIZE = 20.0f;
        const float ACCELERATION = 20.0f;
        const float INITIAL_SPEED = 100.0f;
        Position2D position;
        float speed = INITIAL_SPEED;
        sf::RectangleShape shape;
        sf::Sprite sprite;
        MoveDirection direction = MoveDirection::None;
    };

    void InitializePlayer(Player& player);
    void CalculatePlayerMovement(Player& player, const float deltaTime);
}