#pragma once

namespace sf
{
	class Sprite;
}

namespace ApplesGame
{
	class sf::Sprite;
	
	struct Vector2D
	{
		float x = 0;
		float y = 0;
	};

	typedef Vector2D Position2D;
	
	bool CheckSphereCollision(const Vector2D& object, const Vector2D& other,
		const float objectSize, const float otherSize);
	bool CheckRectangleCollision(const Vector2D& object, const Vector2D& other,
		const float objectSize, const float otherSize);
	bool CheckBoundsCollision(const Vector2D& position, float size);
	void SetRandomPosition(Vector2D& position, float screenWidth, float screenHeight);
	void SetSpriteSize(sf::Sprite& sprite, float desiredWidth, float desiredHeight);
	void SetSpriteRelativeOrigin(sf::Sprite& sprite, float originX, float originY);
}
