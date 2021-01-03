#include <SDL2/SDL.h>
#include <Game.h>
#include <iostream>

Game* game;

int main(int argc, char* argv[])
{
    if(TheGame::Instance()->init(
        "My Game",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        640,
        480,
        false
    ))
    {
        std::cout << "Game init success!\n";
        while (TheGame::Instance()->running())
        {
            TheGame::Instance()->handleEvents();
            TheGame::Instance()->update();
            TheGame::Instance()->render();

            SDL_Delay(10);
        }
    }
    else
    {
        std::cout << "Game init failure - " << SDL_GetError() << std::endl;
        return -1;
    }

    std::cout << "Closing game...\n";
    TheGame::Instance()->clean();

    return 0;    
}
