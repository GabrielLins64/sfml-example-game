#ifndef __GameObject__
#define __GameObject__

#include <SDL2/SDL.h>
#include <TextureManager.h>
#include <iostream>

class GameObject
{
public:

    virtual void load(int x, int y, int width, int height, std::string textureID);
    virtual void draw(SDL_Renderer* renderer);
    virtual void update();
    virtual void clean();

protected:

    std::string textureID;

    int currentFrame;
    int currentRow;

    int x;
    int y;

    int width;
    int height;
};

#endif /* defined(__GameObject__) */