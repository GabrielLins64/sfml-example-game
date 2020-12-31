#include <SDL2/SDL.h>
#include <Game.h>
#include <iostream>

Game* game;

int main(int argc, char* argv[])
{
    game = new Game();

    game->init(
        "My Game",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        640,
        480,
        false
    );

    while (game->running())
    {
        game->handleEvents();
        game->update();
        game->render();

        SDL_Delay(10);
    }
    game->clean();    

    return 0;    
}
