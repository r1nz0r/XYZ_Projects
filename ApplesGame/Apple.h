#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Math.h"

namespace ApplesGame
{
    struct Game;

    struct Apple : Circle
    {
        bool isEaten = false;
        sf::Sprite sprite;
    };

    void InitializeApples(std::vector<Apple>& apples, const Game& game);
    void SetApplePosition(Apple& apple);
    void DrawApple(const Apple& apple, sf::RenderWindow& window);
}
