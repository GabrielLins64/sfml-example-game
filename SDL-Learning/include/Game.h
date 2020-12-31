#ifndef __Game__
#define __Game__

#include <SDL2/SDL.h>
#include <TextureManager.h>
#include <GameObject.h>
#include <Player.h>
#include <Enemy.h>
#include <iostream>
#include <vector>

class Game
{
public:

    Game() {}
    ~Game() {}

    /**
     * @brief Game class initializer
     * 
     * @param title Window title
     * @param xpos Window x position with respect to screen
     * @param ypos Window y position with respect to screen
     * @param width Window starting width
     * @param height Window starting height
     * @param fullscreen If it's fullscreen or not.
     * @return true If was able to instantiate the Game object
     * @return false If something went wrong
     */
    bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void render();

    void update();

    void handleEvents();

    void clean();

    bool running();

private:

    SDL_Window* window;
    SDL_Renderer* renderer;
    bool _running;

    int currentFrame;

    GameObject* go;
    GameObject* player;
    GameObject* enemy;

    std::vector<GameObject*> gameObjects;
};

#endif /* defined(__Game__) */
