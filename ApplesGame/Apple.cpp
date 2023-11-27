#include "Apple.h"
#include "Constants.h"
#include "Math.h"
#include "Game.h"

namespace ApplesGame
{
    void InitializeApples(std::vector<Apple>& apples, const Game& game)
    {
        apples.resize(game.applesAmount);

        for (int i = 0; i < game.applesAmount; ++i)
        {
            apples[i].isEaten = false;
            SetRandomPosition(apples[i].position, SCREEN_WIDTH, SCREEN_HEIGHT);
            apples[i].sprite.setPosition(apples[i].position.x, apples[i].position.y);
            apples[i].sprite.setTexture(game.appleTexture);
            SetSpriteSize(apples[i].sprite, apples[i].SIZE, apples[i].SIZE);
            SetSpriteRelativeOrigin(apples[i].sprite, 0.5f, 0.5f);
        }
    }

    void DrawApple(Apple& apple, sf::RenderWindow& window)
    {
        window.draw(apple.sprite);
    }
}
