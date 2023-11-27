#pragma once
#include "Math.h"
#include <SFML/Graphics.hpp>
#include <string>

namespace ApplesGame
{
    struct Label
    {
        bool isVisible = true;
        Position2D position;
        std::string message;
        sf::Text text;
        sf::Font textFont;
        sf::Color color = sf::Color::Cyan;
        unsigned textSize = 15;
    };

    void InitializeLabel(Label& label);
}
