#include <Enemy.h>

Enemy::Enemy(const LoaderParams* params) : SDLGameObject(params) {}

void Enemy::draw(SDL_Renderer* renderer)
{
    SDLGameObject::draw(renderer);
}

void Enemy::update()
{
    x += 1;
    currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Enemy::clean() {}
