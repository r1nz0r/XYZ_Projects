// ©2023, XYZ School. All rights reserved.
// Authored by Aleksandr Rybalka (polterageist@gmail.com)

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

const std::string RESOURCES_PATH = "Resources/";

const std::string GAME_TITLE = "Apples Game";
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 800;
const int APPLES_AMOUNT = 30;
const int ROCKS_AMOUNT = 15;
const int RESTART_DELAY = 2;

sf::Text GameScoreText;

enum class Direction
{
    Right,
    Up,
    Left,
    Down,
    None
};

struct Object
{
    const float SIZE = 20.0f;
    float positionX = 0;
    float positionY = 0;
};

struct Apple : public Object
{
    sf::CircleShape shape;
};

struct Rectangle : Object
{
    sf::RectangleShape shape;
};

struct Player : public Rectangle
{
    const float ACCELERATION = 20.0f;
    const float INITIAL_SPEED = 100.0f;
    float speed = INITIAL_SPEED;
    int eatenApples = 0;
    Direction direction = Direction::None;
};

void InitializeShape(const Object& object, const float size, const sf::Color& color, sf::Shape& shape)
{
    shape.setFillColor(color);
    shape.setOrigin(size / 2.f, size / 2.f);
    shape.setPosition(object.positionX, object.positionY);
}

void InitializePlayer(Player& player)
{
    player.positionX = SCREEN_WIDTH / 2.0f;
    player.positionY = SCREEN_HEIGHT / 2.0f;
    player.speed = player.INITIAL_SPEED;
    player.eatenApples = 0;
    player.direction = Direction::None;
    player.shape.setSize(sf::Vector2f(player.SIZE, player.SIZE));

    InitializeShape(player, player.SIZE, sf::Color::Green, player.shape);
}

void SetRandomObjectCoordinates(Object& object)
{
    object.positionX = rand() / (float)RAND_MAX * SCREEN_WIDTH;
    object.positionY = rand() / (float)RAND_MAX * SCREEN_HEIGHT;
}

void InitializeApples(Apple apples[])
{
    for (int i = 0; i < APPLES_AMOUNT; ++i)
    {
        SetRandomObjectCoordinates(apples[i]);
        apples[i].shape.setRadius(apples[i].SIZE / 2.0f);

        InitializeShape(apples[i], apples[i].SIZE, sf::Color::Red, apples[i].shape);
    }
}

void InitializeRocks(Rectangle rocks[])
{
    for (int i = 0; i < ROCKS_AMOUNT; ++i)
    {
        SetRandomObjectCoordinates(rocks[i]);
        rocks[i].shape.setSize(sf::Vector2f(rocks[i].SIZE, rocks[i].SIZE));

        InitializeShape(rocks[i], rocks[i].SIZE, sf::Color::Cyan, rocks[i].shape);
    }
}

void CalculatePlayerMovement(Player& player, const float deltaTime)
{
    //Player movement calculation
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        player.direction = Direction::Right;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        player.direction = Direction::Up;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        player.direction = Direction::Left;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        player.direction = Direction::Down;

    float deltaX = 0, deltaY = 0;

    switch (player.direction)
    {
    case Direction::Right:
        deltaX = 1.f;
        break;
    case Direction::Left:
        deltaX = -1.f;
        break;
    case Direction::Down:
        deltaY = 1.f;
        break;
    case Direction::Up:
        deltaY = -1.f;
        break;
    case Direction::None:
    default:
        deltaX = 0.0f;
        deltaY = 0.0f;
        break;
    }

    player.positionX += deltaX * player.speed * deltaTime;
    player.positionY += deltaY * player.speed * deltaTime;
}

void Restart(sf::RenderWindow& window, Player& player, Apple apples[], Rectangle rocks[])
{
    GameScoreText.setString("You loose! The game will restart in " + std::to_string(RESTART_DELAY) + " seconds");
    window.clear();
    window.draw(GameScoreText);
    window.display();
    sf::sleep(sf::Time(sf::seconds(RESTART_DELAY)));
    InitializePlayer(player);
    InitializeApples(apples);
    GameScoreText.setString("Score: " + std::to_string(player.eatenApples));
}

bool CheckAppleAndPlayerCollision(const Player& player, const Apple& apple)
{
    for (int i = 0; i < APPLES_AMOUNT; ++i)
    {
        //Check circles:
        float squareDistance = (player.positionX - apple.positionX) * (player.positionX - apple.positionX) +
            (player.positionY - apple.positionY) * (player.positionY - apple.positionY);
        float squareRadiusSum = (apple.SIZE + player.SIZE) * (apple.SIZE + player.SIZE) / 4;

        if (squareDistance <= squareRadiusSum)
        {
            return true;
        }
    }

    return false;
}

bool CheckRocksAndPlayerCollision(const Player& player, const Rectangle rocks[])
{
    for (int i = 0; i < ROCKS_AMOUNT; ++i)
    {
        if (fabs(player.positionX - rocks[i].positionX) <= (player.SIZE + rocks[i].SIZE) / 2.0f &&
            fabs(player.positionY - rocks[i].positionY) <= (player.SIZE + rocks[i].SIZE) / 2.0f)
        {
            return true;
        }
    }

    return false;
}

void CheckPlayerCollisions(sf::RenderWindow& window, Player& player, Rectangle rocks[], Apple apples[])
{
    for (int i = 0; i < APPLES_AMOUNT; ++i)
    {
        if (CheckAppleAndPlayerCollision(player, apples[i]))
        {
            SetRandomObjectCoordinates(apples[i]);
            apples[i].shape.setPosition(apples[i].positionX, apples[i].positionY);            
            
            ++player.eatenApples;
            GameScoreText.setString("Score: " + std::to_string(player.eatenApples));
            
            player.speed += player.ACCELERATION;
        }
    }

    if (CheckRocksAndPlayerCollision(player, rocks))
    {
        Restart(window, player, apples, rocks);
    }
}


int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), GAME_TITLE);

    srand(static_cast<unsigned>(time(nullptr)));

    Player player{};
    InitializePlayer(player);

    Apple apples[APPLES_AMOUNT]{};
    InitializeApples(apples);

    Rectangle rocks[ROCKS_AMOUNT];
    InitializeRocks(rocks);

    sf::Clock gameClock;
    float lastTime = gameClock.getElapsedTime().asSeconds();

    sf::Font textFont;
    textFont.loadFromFile("E:/XYZ/xyz-cpp-course-template-latest/ApplesGame/Resources/Fonts/Roboto-Black.ttf");

    GameScoreText.setFont(textFont);
    GameScoreText.setCharacterSize(20);
    GameScoreText.setString("Score: " + std::to_string(player.eatenApples));
    GameScoreText.setPosition(10.0f, 10.0f);
    GameScoreText.setFillColor(sf::Color::Yellow);

    while (window.isOpen())
    {
        //Calculate delta time
        float currentTime = gameClock.getElapsedTime().asSeconds();
        float deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        //Read events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        CalculatePlayerMovement(player, deltaTime);

        // Check bounds
        if (player.positionX - player.SIZE / 2.f <= 0 || player.positionX + player.SIZE / 2.f >= SCREEN_WIDTH
            || player.positionY - player.SIZE / 2.f <= 0 || player.positionY + player.SIZE / 2.f >= SCREEN_HEIGHT)
        {
            Restart(window, player, apples, rocks);
            continue;
        }

        CheckPlayerCollisions(window, player, rocks, apples);

        window.clear();
        player.shape.setPosition(player.positionX, player.positionY);
        window.draw(player.shape);

        for (const Apple& apple : apples)
        {
            window.draw(apple.shape);
        }

        for (const Rectangle& rock : rocks)
        {
            window.draw(rock.shape);
        }

        window.draw(GameScoreText);
        window.display();
    }

    return 0;
}
