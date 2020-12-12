#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SFML/Graphics.hpp>

struct sprite_t {
    sf::Texture texture;
    sf::Sprite sprite;
};

void loadTexture(sprite_t &sprite, const char* path);
sf::RectangleShape drawRect(sf::Vector2f viewSize);
sf::CircleShape drawCircle(sf::Vector2f viewSize);
sf::ConvexShape drawTriangle(sf::Vector2f viewSize);

#endif
