#ifndef GAME_H
#define GAME_H

#include <global.h>
#include <io.h>

sf::Vector2f viewSize;
sf::VideoMode vm;
sf::RenderWindow window;
const float FPS = 60.0f;

sprite_t skySprite;
sprite_t bgSprite;
sprite_t heroSprite;

sf::Vector2f playerPosition;
bool playerMoving;
float playerVelocity;

void update(float delta);
void init();
void draw();
void game_loop();

#endif