#ifndef __SDLGameObj__
#define __SDLGameObj__

#include <GameObject.h>

class SDLGameObject : public GameObject
{
public:

    SDLGameObject(const LoaderParams* params);
    virtual void draw(SDL_Renderer* renderer);
    virtual void update();
    virtual void clean();

protected:

    int x;
    int y;
    int width;
    int height;
    int currentFrame;
    int currentRow;
    SDL_Renderer* renderer;
    std::string textureID;
};

#endif