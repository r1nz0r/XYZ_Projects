#pragma once

namespace ApplesGame
{
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

}