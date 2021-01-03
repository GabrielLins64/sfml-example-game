#include <SDLGameObject.h>

SDLGameObject::SDLGameObject(const LoaderParams* params) : GameObject(params)
{
    x = params->getX();
    y = params->getY();
    width = params->getWidth();
    height = params->getHeight();
    textureID = params->getTextureID();
    currentFrame = 0;
    currentRow = 1;
}

void SDLGameObject::draw(SDL_Renderer* renderer)
{
    TextureManager::Instance()->drawFrame(textureID, x, y, width, 
                                          height, currentRow, currentFrame,
                                          renderer);
}

void SDLGameObject::update() {}

void SDLGameObject::clean() {}
