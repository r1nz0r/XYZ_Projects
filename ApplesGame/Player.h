#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"

namespace ApplesGame
{
    struct Game;

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
        const float INITIAL_SPEED = 200.0f;
        Position2D position;
        float speed = INITIAL_SPEED;
        sf::Sprite sprite;
        MoveDirection direction = MoveDirection::None;
    };

    void InitializePlayer(Player& player, const Game& game);
    void CalculatePlayerMovement(Player& player, const float deltaTime);
    void DrawPlayer(Player& player, sf::RenderWindow& window);
    void RotatePlayer(Player& player);
}