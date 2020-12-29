#include <hero.h>

Hero::Hero()
{

}

Hero::~Hero()
{

}

void Hero::init(const char* textureName, int frameCount, float animDuration, sf::Vector2f position, float mass)
{
    m_position = position;
    m_mass = mass;
    m_grounded = false;
    m_frameCount = frameCount;
    m_animDuration = animDuration;
    m_spriteSize = sf::Vector2i(92, 126);

    m_sprite.texture.loadFromFile(textureName);
    m_sprite.sprite.setTexture(m_sprite.texture);
    m_sprite.sprite.setTextureRect(sf::IntRect(0, 0, m_spriteSize.x, m_spriteSize.y));
    m_sprite.sprite.setPosition(m_position);
    m_sprite.sprite.setOrigin(m_spriteSize.x/2, m_spriteSize.y/2);
}

void Hero::update(float dt)
{
    m_elapsedTime += dt;
    int animFrame = static_cast<int> ((m_elapsedTime / m_animDuration) * m_frameCount) % m_frameCount;
    m_sprite.sprite.setTextureRect(sf::IntRect(animFrame * m_spriteSize.x, 0, m_spriteSize.x, m_spriteSize.y));

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
