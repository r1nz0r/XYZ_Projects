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
            SetRockPosition(rocks[i]);
            rocks[i].sprite.setTexture(game.rockTexture);
            rocks[i].size = Vector2D(20.0f, 20.0f);

            SetSpriteSize(rocks[i].sprite, rocks[i].size.x, rocks[i].size.y);
            SetSpriteRelativeOrigin(rocks[i].sprite, 0.5f, 0.5f);
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
