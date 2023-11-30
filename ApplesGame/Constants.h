#pragma once
#include <string>

namespace ApplesGame
{
    const std::string RESOURCES_PATH = "Resources/";
    const std::string FONT_NAME = "/Fonts/Roboto-Black.ttf";
    const std::string GAME_TITLE = "Apples Game";
    constexpr int SCREEN_WIDTH = 1200;
    constexpr int SCREEN_HEIGHT = 800;
    constexpr int APPLES_AMOUNT_MIN = 30;
    constexpr int APPLES_AMOUNT_MAX = 50;
    constexpr int ROCKS_AMOUNT_MIN = 25;
    constexpr int ROCKS_AMOUNT_MAX = 40;
    constexpr int RESTART_DELAY = 2;
    constexpr float INITIAL_ANGLE = 0.0f;
    constexpr float ROTATION_ANGLE = -90.0f;
}
