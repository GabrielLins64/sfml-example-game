#include <TextureManager.h>

TextureManager* TextureManager::instance = 0;

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* renderer)
{
    SDL_Surface* tmpSurface = IMG_Load(fileName.c_str());

    if (tmpSurface == 0) return false;

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);

    if (texture != 0)
    {
        textureMap[id] = texture;
        return true;
    }

    return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, 
                          SDL_Renderer* renderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect dstRect;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = dstRect.w = width;
    srcRect.h = dstRect.h = height;

    dstRect.x = x;
    dstRect.y = y;

    SDL_RenderCopyEx(renderer, textureMap[id], &srcRect, &dstRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height,
                int currentRow, int currentFrame, SDL_Renderer* renderer,
                SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect dstRect;

    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);
    srcRect.w = dstRect.w = width;
    srcRect.h = dstRect.h = height;
    dstRect.x = x;
    dstRect.y = y;

    SDL_RenderCopyEx(renderer, textureMap[id], &srcRect, &dstRect, 0, 0, flip);
}
