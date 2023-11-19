#pragma once
#include "CommonObjects.h"
#include "Game.h"

void SetRandomObjectCoordinates(Object& object, float screenWidth, float screenHeight);
bool CheckAppleAndPlayerCollision(const Player& player, const Apple& apple);
bool CheckRocksAndPlayerCollision(const Player& player, const Rectangle rocks[]);
bool CheckBoundsCollision(const Game& game);
void CheckPlayerCollisions(sf::RenderWindow& window, Game& game);