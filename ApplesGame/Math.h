#pragma once
#include "SFML/System/Vector2.hpp"

namespace sf
{
    class Sprite;
}

namespace ApplesGame
{    
    class sf::Sprite;

    typedef sf::Vector2f Vector2D; 
    typedef sf::Vector2f Position2D;
    
    struct Circle
    {
        Vector2D position;
        float radius;
    };

    struct Rectangle
    {
        Vector2D position;
        Vector2D size;
    };       
	
    bool CheckCircleCollision(const Circle& object, const Circle& other);
    bool CheckRectangleCollision(const Rectangle& object, const Rectangle& other);
    bool CheckCircleAndRectangleCollision(const Circle& circle, const Rectangle& rectangle);
    bool CheckCircleBoundsCollision(const Circle& object);
    int GetRandomInt(int minValue, int maxValue);
    float GetRandomFloat(float minValue, float maxValue);
    void SetRandomPosition(Vector2D& position, float screenWidth, float screenHeight);	
    void SetSpriteSize(sf::Sprite& sprite, float desiredWidth, float desiredHeight);
    void SetSpriteRelativeOrigin(sf::Sprite& sprite, float originX, float originY);
    
}