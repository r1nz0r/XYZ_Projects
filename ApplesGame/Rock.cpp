#include "Rock.h"
#include "Constants.h"
#include "Math.h"
#include "Game.h"

namespace ApplesGame
{
    void InitializeRocks(std::vector<Rock>& rocks, const Game& game)
    {
        rocks.resize(game.rocksAmount);

        for (int i = 0; i < game.rocksAmount; ++i)
        {
            SetRandomColliderPosition(rocks[i].position, SCREEN_WIDTH, SCREEN_HEIGHT);
            rocks[i].size.x = 20.0f;
            rocks[i].size.y = 20.0f;
            
            bool isCollisionFree = true;
            
            for (const auto& apple : game.apples)
            {
                if (CheckCircleAndRectangleCollision(apple, rocks[i]))
                {
                    isCollisionFree = false;
                    break;
                }            
            }

            for (int j = 0; j < game.rocksAmount; ++ j)
            {
                if (j == i)
                    continue;
                
                if (CheckRectangleCollision(rocks[j], rocks[i]))
                {
                    isCollisionFree = false;
                    break;
                }
            }

            if (isCollisionFree)
            {
                SetRockPosition(rocks[i]);
                rocks[i].sprite.setTexture(game.rockTexture);              
                SetSpriteSize(rocks[i].sprite, rocks[i].size.x, rocks[i].size.y);
                SetSpriteRelativeOrigin(rocks[i].sprite, 0.5f, 0.5f);
            }
            else
            {
                --i;
            }
        }
    }

    void DrawRock(const Rock& rock, sf::RenderWindow& window)
    {
        window.draw(rock.sprite);
    }

    void SetRockPosition(Rock& rock)
    {
        rock.sprite.setPosition(rock.position.x + rock.size.x / 2.f, rock.position.y + rock.size.y / 2.f);
    }
}
