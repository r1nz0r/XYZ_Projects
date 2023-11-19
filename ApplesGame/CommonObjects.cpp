#include "CommonObjects.h"

void InitializeShape(const Object& object, const float size, const sf::Color& color, sf::Shape& shape)
{
    shape.setFillColor(color);
    shape.setOrigin(size / 2.f, size / 2.f);
    shape.setPosition(object.positionX, object.positionY);
}