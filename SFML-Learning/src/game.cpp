#include <game.h>

void update(float delta)
{
    hero.update(delta);
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
}

void draw()
{
    window.draw(skySprite.sprite);
    window.draw(bgSprite.sprite);
    window.draw(hero.getSprite());
}

void game_loop()
{
    init();
    sf::Clock clock;
    sf::Event event;
    sf::Time delta;

    while(window.isOpen()) 
    {
        sf::Event event;
        updateInput();
        delta = clock.restart();
        update(delta.asSeconds());
        window.clear(sf::Color::Blue);
        draw();
        window.display();
    }
}
