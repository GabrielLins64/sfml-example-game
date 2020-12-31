#include <Enemy.h>

void Enemy::update()
{
    y += 1;
    x += 1;
    currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Enemy::load(int x, int y, int width, int height, std::string textureID)
{
    GameObject::load(x, y, width, height, textureID);
}

void Enemy::draw(SDL_Renderer* renderer)
{
    GameObject::draw(renderer);
}

void Enemy::clean()
{
    GameObject::clean();
}
