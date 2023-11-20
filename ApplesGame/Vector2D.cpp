#include "Vector2D.h"

namespace ApplesGame
{
    void InitializeShape(const Vector2D& object, const float size, const sf::Color& color, sf::Shape& shape)
    {
        shape.setFillColor(color);
        shape.setOrigin(size / 2.f, size / 2.f);
        shape.setPosition(object.x, object.y);
    }
	
    void SetRandomPosition(Vector2D& object, float screenWidth, float screenHeight)
    {
        object.x = rand() / (float)RAND_MAX * screenWidth;
        object.y = rand() / (float)RAND_MAX * screenHeight;
    }
}
