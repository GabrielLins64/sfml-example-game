#ifndef HERO_H
#define HERO_H

#include <global.h>

/** Game hero class */
class Hero 
{
    private:
        sprite_t m_sprite;
        sf::Vector2f m_position;

        int jumpCount = 2;
        float m_mass;
        float m_velocity;
        const float m_gravity = 9.80f;
        bool m_grounded;

        int m_frameCount;
        float m_animDuration;
        float m_elapsedTime;
        sf::Vector2i m_spriteSize;

    public:
        Hero();
        ~Hero();

        /**
         * @brief Initialization method
         * 
         * @param textureName Relative path to the hero texture image
         * @param frameCount Number of frames in the hero animation
         * @param animDuration Determines the speed of the animation
         * @param position Hero's initial position
         * @param mass Hero's mass. Affects its jumps
         */
        void init(const char* textureName, int frameCount, float animDuration, sf::Vector2f position, float mass);
        void update(float dt);
        void jump(float velocity);

        sf::Sprite getSprite();
};

#endif
