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
            SetRandomColliderPosition(apples[i].position, SCREEN_WIDTH, SCREEN_HEIGHT);
            apples[i].radius = 10.0f;

            bool isCollisionFree = true;

            for (int j = 0; j < game.applesAmount; ++j)
            {
                if (j == i)
                    continue;

                if (CheckCircleCollision(game.apples[j], game.apples[i]))
                {
                    isCollisionFree = false;
                    break;
                }
            }

            if (isCollisionFree)
            {
                SetApplePosition(apples[i]);
                apples[i].sprite.setTexture(game.appleTexture);
                SetSpriteSize(apples[i].sprite, apples[i].radius * 2.f, apples[i].radius * 2.f);
                SetSpriteRelativeOrigin(apples[i].sprite, 0.5f, 0.5f);
            }
            else
            {
                --i;
            }
        }
    }

    void SetApplePosition(Apple& apple)
    {
        apple.sprite.setPosition(apple.position.x, apple.position.y);
    }

    void DrawApple(const Apple& apple, sf::RenderWindow& window)
    {
        window.draw(apple.sprite);
    }
}
