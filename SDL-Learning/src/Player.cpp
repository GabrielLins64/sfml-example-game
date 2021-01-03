#include <Player.h>

Player::Player(const LoaderParams* params) : SDLGameObject(params) {}

void Player::draw(SDL_Renderer* renderer)
{
    SDLGameObject::draw(renderer);
}

void Player::update()
{
    x -= 1;
    currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Player::clean() {}
