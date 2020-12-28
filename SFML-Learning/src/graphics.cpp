#include <graphics.h>

void loadTexture(sprite_t &sprite, const char* path)
{
    sprite.texture.loadFromFile(path);
    sprite.sprite.setTexture(sprite.texture);
}

sf::RectangleShape drawRect(sf::Vector2f viewSize)
{
    sf::RectangleShape rect(sf::Vector2f(500.0f, 300.0f));
    rect.setFillColor(sf::Color::Yellow);
    rect.setPosition(viewSize.x/2, viewSize.y/2);
    float originX = rect.getSize().x/2;
    float originY = rect.getSize().y/2;
    rect.setOrigin(sf::Vector2f(originX, originY));
    return rect;
}

sf::CircleShape drawCircle(sf::Vector2f viewSize)
{
    sf::CircleShape circle(100);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(viewSize.x/2, viewSize.y/2);
    circle.setOrigin(sf::Vector2f(circle.getRadius(), circle.getRadius()));
    return circle;
}

sf::ConvexShape drawTriangle(sf::Vector2f viewSize)
{
    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(-100, 0));
    triangle.setPoint(1, sf::Vector2f(0, -100));
    triangle.setPoint(2, sf::Vector2f(100, 0));
    triangle.setFillColor(sf::Color(128, 0, 128, 255));
    triangle.setPosition(viewSize.x/2, viewSize.y/2);
    return triangle;
}
