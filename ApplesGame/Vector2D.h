#pragma once
#include <SFML/Graphics.hpp>

namespace ApplesGame
{
    struct Vector2D
    {
        float x = 0;
        float y = 0;
    };

    void InitializeShape(const Vector2D& object, const float size, const sf::Color& color, sf::Shape& shape);
    void SetRandomPosition(Vector2D& object, float screenWidth, float screenHeight);
}

