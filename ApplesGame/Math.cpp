#include "Math.h"
#include "Constants.h"
#include <SFMl/Graphics.hpp>

namespace ApplesGame
{
	bool CheckSphereCollision(const Vector2D& object, const Vector2D& other,
		const float objectSize, const float otherSize)
	{
		float squareDistance = (object.x - other.x) * (object.x - other.x) +
			(object.y - other.y) * (object.y - other.y);
		float squareRadiusSum = (objectSize + otherSize) * (objectSize + otherSize) / 4;

		if (squareDistance <= squareRadiusSum)
		{
			return true;
		}

		return false;
	}

	bool CheckRectangleCollision(const Vector2D& object, const Vector2D& other,
		const float objectSize, const float otherSize)
	{
		if (fabs(object.x - other.x) <= (objectSize + otherSize) / 2.0f &&
				fabs(object.y - other.y) <= (objectSize + otherSize) / 2.0f)
		{
			return true;
		}

		return false;
	}

	bool CheckBoundsCollision(const Vector2D& position, const float size)
	{
		if (position.x - size / 2.f <= 0 ||
			position.x + size / 2.f >= SCREEN_WIDTH ||
			position.y - size / 2.f <= 0 ||
			position.y + size / 2.f >= SCREEN_HEIGHT)
		{
			return true;
		}

		return false;
	}

	void SetRandomPosition(Vector2D& position, float screenWidth, float screenHeight)
	{
		position.x = rand() / (float)RAND_MAX * screenWidth;
		position.y = rand() / (float)RAND_MAX * screenHeight;
	}
	
	void SetSpriteSize(sf::Sprite& sprite, float desiredWidth, float desiredHeight)
	{
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		sf::Vector2f scale = {desiredWidth / spriteRect.width, desiredHeight / spriteRect.height};
		sprite.setScale(scale);
	}

	void SetSpriteRelativeOrigin(sf::Sprite& sprite, float originX, float originY)
	{
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		sprite.setOrigin(originX * spriteRect.width, originY * spriteRect.height);
	}
}
