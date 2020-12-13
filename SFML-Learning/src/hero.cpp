#include <hero.h>

Hero::Hero()
{

}

Hero::~Hero()
{

}

void Hero::init(const char* textureName, sf::Vector2f position, float mass)
{
    m_position = position;
    m_mass = mass;
    m_grounded = false;
    m_sprite.texture.loadFromFile(textureName);
    m_sprite.sprite.setTexture(m_sprite.texture);
    m_sprite.sprite.setPosition(m_position);
    m_sprite.sprite.setOrigin(m_sprite.texture.getSize().x/2, m_sprite.texture.getSize().y/2);
}

void Hero::update(float dt)
{
    m_velocity -= m_mass * m_gravity * dt;
    m_position.y -= m_velocity * dt;
    m_sprite.sprite.setPosition(m_position);

    if (m_position.y >= WINDOW_HEIGHT * 0.75f)
    {
        m_position.y = WINDOW_HEIGHT * 0.75f;
        m_velocity = 0;
        m_grounded = true;
        jumpCount = 0;
    }
}

void Hero::jump(float velocity)
{
    if (jumpCount < 2)
    {
        jumpCount++;
        m_velocity = velocity;
        m_grounded = false;
    }
}

sf::Sprite Hero::getSprite()
{
    return m_sprite.sprite;
}
