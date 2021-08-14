#pragma once
#include <global.h>

class Enemy
{
    public:
        Enemy();
        ~Enemy();

        void init(const char* textureName, sf::Vector2f position, float _speed);
        void update(float dt);

        sf::Sprite getSprite();

    private:
        sprite_t m_sprite;
        sf::Vector2f m_position;
        float m_speed;
};
