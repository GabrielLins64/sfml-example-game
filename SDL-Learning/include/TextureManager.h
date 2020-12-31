#ifndef __TextureManager__
#define __TextureManager__

#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <map>

class TextureManager
{
public:

    static TextureManager* Instance()
    {
        if (instance == 0)
        {
            instance = new TextureManager();
            return instance;
        }
        return instance;
    }

    bool load(std::string fileName, std::string id, SDL_Renderer* renderer);

    void draw(std::string id, int x, int y, int width, int height, 
            SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    void drawFrame(std::string id, int x, int y, int width, int height,
                int currentRow, int currentFrame, SDL_Renderer* renderer,
                SDL_RendererFlip flip = SDL_FLIP_NONE);

private:

    TextureManager() {}
    ~TextureManager() {}

    std::map<std::string, SDL_Texture*> textureMap;

    static TextureManager* instance;
};

typedef TextureManager TheTextureManager;

#endif /* defined(__TextureManager__) */
