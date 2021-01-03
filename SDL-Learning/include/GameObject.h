#ifndef __GameObject__
#define __GameObject__

#include <SDL2/SDL.h>
#include <TextureManager.h>
#include <LoaderParams.h>
#include <iostream>

class GameObject
{
public:

    virtual void draw(SDL_Renderer* renderer) = 0;
    virtual void update() = 0;
    virtual void clean() = 0;

protected:

    GameObject(const LoaderParams* params) {}
    virtual ~GameObject() {}
};

#endif /* defined(__GameObject__) */