#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SFML/Graphics.hpp>

struct sprite_t {
    sf::Texture texture;
    sf::Sprite sprite;
};

struct text_t {
    sf::Font font;
    sf::Text text;
};

void loadTexture(sprite_t &sprite, const char* path);
void loadText(text_t &text, const char* fontPath, const char* string, int charSize, sf::Color color);
void moveText(text_t &text, sf::Vector2f position);
sf::RectangleShape drawRect(sf::Vector2f viewSize);
sf::CircleShape drawCircle(sf::Vector2f viewSize);
sf::ConvexShape drawTriangle(sf::Vector2f viewSize);

#endif
