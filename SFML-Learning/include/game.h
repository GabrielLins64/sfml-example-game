#ifndef GAME_H
#define GAME_H

#include <global.h>
#include <io.h>
#include <enemy.h>
#include <rocket.h>
#include <vector>

sf::Vector2f viewSize;
sf::VideoMode vm;
sf::RenderWindow window;
const float FPS = 60.0f;

sprite_t skySprite;
sprite_t bgSprite;

Hero hero;
sf::Vector2f playerPosition;
bool playerMoving;
float playerVelocity;
std::vector<Enemy*> enemies;
std::vector<Rocket*> rockets;

float currentTime;
float prevTime = 0.0f;

void update(float delta);
void init();
void draw();
void game_loop();
void spawnEnemy();
void shoot();
bool checkCollision(sf::Sprite sprite1, sf::Sprite sprite2);

#endif
