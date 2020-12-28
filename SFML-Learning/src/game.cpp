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
            gameover = true;
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
                hitSound.play();
                to_score();
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

    loadTexture(skySprite, "assets/graphics/sky.png");
    loadTexture(bgSprite, "assets/graphics/bg.png");
    loadText(headingText, "assets/fonts/SnackerComic.ttf", "Tiny Bazooka", 84, sf::Color::Red);
    loadText(scoreText, "assets/fonts/arial.ttf", "Score: 0", 45, sf::Color::Yellow);
    loadText(tutorialText, "assets/fonts/arial.ttf", 
                           "Press \"Space\" to fire, \"Enter\" to start and \"Up arrow\" to jump.\nDon't let your enemies reach the left of the screen.\nYou can also double jump by pressing for jump twice!", 
                           35, sf::Color(0, 191, 255, 255));

    moveText(headingText, sf::Vector2f(viewSize.x * 0.5f, viewSize.y * 0.10f));
    moveText(scoreText, sf::Vector2f(viewSize.x * 0.16f, viewSize.y * 0.12f));
    moveText(tutorialText, sf::Vector2f(viewSize.x * 0.5f, viewSize.y * 0.30f));

    hero.init("assets/graphics/hero.png", sf::Vector2f(viewSize.x * 0.25f, viewSize.y * 0.5f), 200);

    bgMusic.openFromFile("assets/audio/bgMusic.ogg");
    bgMusic.setVolume(20);
    hitBuffer.loadFromFile("assets/audio/hit.ogg");
    fireBuffer.loadFromFile("assets/audio/fire.ogg");
    bgMusic.play();

    srand((int)time(0));
}

void draw()
{
    window.draw(skySprite.sprite);
    window.draw(bgSprite.sprite);
    window.draw(hero.getSprite());
    window.draw(scoreText.text);

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
        delta = clock.restart();
        window.clear(sf::Color::Blue);
        draw();
        if (!gameover) {
            updateInput(event);
            update(delta.asSeconds());
        } else {
            window.draw(headingText.text);
            window.draw(tutorialText.text);
            updateInputGameOver(event);
        }
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
    fireSound.play();
}

bool checkCollision(sf::Sprite sprite1, sf::Sprite sprite2)
{
    sf::FloatRect shape1 = sprite1.getGlobalBounds();
    sf::FloatRect shape2 = sprite2.getGlobalBounds();

    if (shape1.intersects(shape2)) return true;

    return false;    
}

void quit()
{
    reset();
    window.close();
}

void reset() {
    score = 0;
    currentTime = 0.0f;
    prevTime = 0.0;
    scoreText.text.setString("Score: 0");

    for (Enemy *enemy : enemies) delete(enemy);
    for (Rocket *rocket : rockets) delete(rocket);
    enemies.clear();
    rockets.clear();
}

inline void to_score()
{
    score++;
    std::string finalScore = "Score: " + std::to_string(score);
    scoreText.text.setString(finalScore);
    moveText(scoreText, sf::Vector2f(viewSize.x * 0.15f, viewSize.y * 0.10f));
}
