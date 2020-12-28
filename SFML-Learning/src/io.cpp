#include <io.h>

void updateInput(sf::Event event)
{
    while(window.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Up) hero.jump(750.0f);
            if (event.key.code == sf::Keyboard::Space) shoot();
        } 
        
        if (event.key.code == sf::Keyboard::Escape || 
            event.type == sf::Event::Closed)
                quit();
    }
}

void updateInputGameOver(sf::Event event)
{
    while(window.pollEvent(event))
    {
        if (event.key.code == sf::Keyboard::Return)
            if (gameover) {
                gameover = false;
                reset();
            }
        if (event.key.code == sf::Keyboard::Escape || 
            event.type == sf::Event::Closed)
                quit();
    }
}
