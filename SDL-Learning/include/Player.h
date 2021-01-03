#ifndef __Player__
#define __Player__

#include <SDLGameObject.h>

class Player : public SDLGameObject
{
public:

    Player(const LoaderParams* params);

    virtual void draw(SDL_Renderer* renderer);
    virtual void update();
    virtual void clean();
};

#endif /* defined(__Player__) */