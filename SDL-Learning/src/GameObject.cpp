#include <GameObject.h>

void GameObject::load(int x, int y, int width, int height, std::string textureID)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->textureID = textureID;

    currentFrame = 1;
    currentRow = 1;
}

void GameObject::draw(SDL_Renderer* renderer)
{
    TextureManager::Instance()->drawFrame(textureID, x, y, width, height, 
                                          currentRow, currentFrame, renderer);
}

void GameObject::update()
{
    x += 1;
}

void GameObject::clean()
{

}