#ifndef HERO_H
#define HERO_H

#include <global.h>

class Hero 
{
    private:
        sprite_t m_sprite;
        sf::Vector2f m_position;

        int jumpCount = 0;
        float m_mass;
        float m_velocity;
        const float m_gravity = 9.80f;
        bool m_grounded;

    public:
        Hero();
        ~Hero();

        void init(const char* textureName, sf::Vector2f position, float mass);
        void update(float dt);
        void jump(float velocity);
        sf::Sprite getSprite();
};

#endif