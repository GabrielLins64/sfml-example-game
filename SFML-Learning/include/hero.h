#ifndef HERO_H
#define HERO_H

#include <global.h>

/** Game hero class */
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

        /**
         * @brief Initialization method
         * 
         * @param textureName Relative path to the hero texture image
         * @param position Hero initial position
         * @param mass Hero mass. Affects its jumps
         */
        void init(const char* textureName, sf::Vector2f position, float mass);
        void update(float dt);
        void jump(float velocity);

        sf::Sprite getSprite();
};

#endif
