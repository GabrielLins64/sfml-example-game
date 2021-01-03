#ifndef __Game__
#define __Game__

#include <SDL2/SDL.h>
#include <Player.h>
#include <Enemy.h>
#include <iostream>
#include <vector>

class Game
{
public:

    static Game* Instance()
    {
        if(instance == 0)
        {
            instance = new Game();
            return instance;
        }
        return instance;
    }

    /**
     * @brief Game class initializer
     * 
     * @param title Window title
     * @param xpos Window x position with respect to screen
     * @param ypos Window y position with respect to screen
     * @param width Window starting width
     * @param height Window starting height
     * @param fullscreen If it's fullscreen or not.
     * @return true If was able to instantiate the Game class
     * @return false If something went wrong
     */
    bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void render();

    void update();

    void handleEvents();

    void clean();

    bool running();

    SDL_Renderer* getRenderer() const;

private:

    Game() {}
    ~Game() {}
    static Game* instance;

    SDL_Window* window;
    SDL_Renderer* renderer;
    bool _running;

    std::vector<SDLGameObject*> gameObjects;
};

typedef Game TheGame;

#endif /* defined(__Game__) */
