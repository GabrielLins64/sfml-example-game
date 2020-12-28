#include <game.h>

void update(float delta)
{
    hero.update(delta);
    currentTime += delta;
    if (currentTime >= prevTime + 1.125f) {
        spawnEnemy();
        prevTime = currentTime;
    }

    // Updating and cleaning enemies
    for(int i = 0; i < enemies.size(); i++) {
        Enemy *enemy = enemies[i];
        enemy->update(delta);
        if (enemy->getSprite().getPosition().x < 0) {
            enemies.erase(enemies.begin() + i);
            delete(enemy);
        }
    }

    // Updating and cleaning rockets
    for (int i = 0; i < rockets.size(); i++) {
        Rocket* rocket = rockets[i];
        rocket->update(delta);
        if (rocket->getSprite().getPosition().x > viewSize.x) {
            rockets.erase(rockets.begin() + i);
            delete(rocket);
        }
    }

    // Check collision between Rocket and Enemies
    for (int i = 0; i < rockets.size(); i++) {
        for (int j = 0; j < enemies.size(); j++) {
            Rocket* rocket = rockets[i];
            Enemy* enemy = enemies[j];
            if (checkCollision(rocket->getSprite(), enemy->getSprite())) {
                rockets.erase(rockets.begin() + i);
                enemies.erase(enemies.begin() + j);
                delete(rocket);
                delete(enemy);
            }
        }
    }
}

void init()
{
    viewSize = sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT);
    vm = sf::VideoMode(viewSize.x, viewSize.y);
    window.create(vm, 
                "Hello SFMLGame!!!", 
                sf::Style::Default);
    window.setFramerateLimit(FPS);

    playerVelocity = 200.0f;
    playerMoving = false;

    loadTexture(skySprite, "assets/graphics/sky.png");
    loadTexture(bgSprite, "assets/graphics/bg.png");

    hero.init("assets/graphics/hero.png", sf::Vector2f(viewSize.x * 0.25f, viewSize.y * 0.5f), 200);

    srand((int)time(0));
}

void draw()
{
    window.draw(skySprite.sprite);
    window.draw(bgSprite.sprite);
    window.draw(hero.getSprite());

    for(Enemy *enemy : enemies) {
        window.draw(enemy->getSprite());
    }

    for(Rocket* rocket : rockets) {
        window.draw(rocket->getSprite());
    }
}

void game_loop()
{
    init();
    sf::Clock clock;
    sf::Event event;
    sf::Time delta;

    while(window.isOpen()) 
    {
        updateInput(event);
        delta = clock.restart();
        update(delta.asSeconds());
        window.clear(sf::Color::Blue);
        draw();
        window.display();
    }
}

void spawnEnemy()
{
    int randLoc = rand() % 3;
    sf::Vector2f enemyPos;
    float speed;
    switch(randLoc) {
        case 0:
            enemyPos = sf::Vector2f(viewSize.x, viewSize.y * 0.75f);
            speed = -400;
            break;
        case 1:
            enemyPos = sf::Vector2f(viewSize.x, viewSize.y * 0.60f);
            speed = -550;
            break;
        case 2:
            enemyPos = sf::Vector2f(viewSize.x, viewSize.y * 0.40f);
            speed = -650;
            break;
        default:
            printf("Incorrect y value\n");
            return;
    }

    Enemy* enemy = new Enemy();
    enemy->init("assets/graphics/enemy.png", enemyPos, speed);

    enemies.push_back(enemy);
}

void shoot()
{
    Rocket* rocket = new Rocket();
    rocket->init("assets/graphics/rocket.png", hero.getSprite().getPosition(), 400.0f);

    rockets.push_back(rocket);
}

bool checkCollision(sf::Sprite sprite1, sf::Sprite sprite2)
{
    sf::FloatRect shape1 = sprite1.getGlobalBounds();
    sf::FloatRect shape2 = sprite2.getGlobalBounds();

    if (shape1.intersects(shape2)) return true;

    return false;    
}
