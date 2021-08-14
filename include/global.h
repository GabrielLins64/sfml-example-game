#ifndef GLOBAL_H
#define GLOBAL_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <graphics.h>

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

extern sf::Vector2f viewSize;
extern sf::VideoMode vm;
extern sf::RenderWindow window;

extern sprite_t skySprite;
extern sprite_t bgSprite;

extern void game_loop();

#endif
