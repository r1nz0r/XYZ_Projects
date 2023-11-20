#pragma once
#include "Game.h"

struct Vector2D
{
    float positionX = 0;
    float positionY = 0;
};

void SetRandomObjectCoordinates(Vector2D& object, float screenWidth, float screenHeight);
bool CheckAppleAndPlayerCollision(const Player& player, const Apple& apple);
bool CheckRocksAndPlayerCollision(const Player& player, const Rock rocks[]);
bool CheckBoundsCollision(const Game& game);
void CheckPlayerCollisions(sf::RenderWindow& window, Game& game);
void InitializeShape(const Vector2D& object, const float size, const sf::Color& color, sf::Shape& shape);