#include <game.h>

void update(float delta)
{
    if (playerMoving) heroSprite.sprite.move(playerVelocity * delta, 0);
}

void init()
{
    viewSize = sf::Vector2f(1024, 768);
    vm = sf::VideoMode(viewSize.x, viewSize.y);
    window.create(vm, 
                "Hello SFMLGame!!!", 
                sf::Style::Default);
    window.setFramerateLimit(FPS);

    playerVelocity = 200.0f;
    playerMoving = false;

    loadTexture(skySprite, "assets/graphics/sky.png");
    loadTexture(bgSprite, "assets/graphics/bg.png");
    loadTexture(heroSprite, "assets/graphics/hero.png");

    heroSprite.sprite.setPosition(sf::Vector2f(viewSize.x/2, viewSize.y/2));
    heroSprite.sprite.setOrigin(heroSprite.texture.getSize().x/2, heroSprite.texture.getSize().y/2);
}

void draw()
{
    window.draw(skySprite.sprite);
    window.draw(bgSprite.sprite);
    window.draw(heroSprite.sprite);
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
