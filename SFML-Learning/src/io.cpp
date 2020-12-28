#include <io.h>

void updateInput(sf::Event event)
{
    while(window.pollEvent(event))
    {
        // if (event.type == sf::Event::KeyPressed) 
        // {
        //     if (event.key.code == sf::Keyboard::Right) playerMoving = true;
        // }

        // if (event.type == sf::Event::KeyReleased) {
        //     if (event.key.code == sf::Keyboard::Right) playerMoving = false;
        // }

        if (event.type == sf::Event::KeyPressed)
        {
            if(event.key.code == sf::Keyboard::Up) hero.jump(750.0f);
            if(event.key.code == sf::Keyboard::Space) shoot();
        } 
        
        if (event.key.code == sf::Keyboard::Escape || 
            event.type == sf::Event::Closed)
                window.close();
    }
}
