#pragma once
#include <SFML/Graphics.hpp>

struct Vector2D
{
    float positionX = 0;
    float positionY = 0;
};

struct Object : Vector2D
{
    const float SIZE = 20.0f;
};

struct Rectangle : Object
{
    sf::RectangleShape shape;
};

void InitializeShape(const Object& object, const float size, const sf::Color& color, sf::Shape& shape);