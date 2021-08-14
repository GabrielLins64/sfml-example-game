#include <rocket.h>

Rocket::Rocket(){}

Rocket::~Rocket(){}

void Rocket::init(const char* textureName, sf::Vector2f position, float _speed)
{
    m_speed = _speed;
    m_position = position;

    m_sprite.texture.loadFromFile(textureName);
    m_sprite.sprite.setTexture(m_sprite.texture);
    m_sprite.sprite.setPosition(m_position);
    m_sprite.sprite.setOrigin(m_sprite.texture.getSize().x / 2, m_sprite.texture.getSize().y / 2);
}

void Rocket::update(float dt)
{
    m_sprite.sprite.move(m_speed * dt, 0);
}

sf::Sprite Rocket::getSprite()
{
    return m_sprite.sprite;
}
