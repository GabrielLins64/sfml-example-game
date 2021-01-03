#include <Game.h>

Game* Game::instance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags;
    if (fullscreen) flags = SDL_WINDOW_FULLSCREEN;
    else flags = SDL_WINDOW_RESIZABLE;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == 0)
    {
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if (window != 0)
        {
            renderer = SDL_CreateRenderer(window, -1, 0);

            if (renderer != 0)
            {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            }
            else 
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }

    _running = true;

    if(!TheTextureManager::Instance()->load("assets/graphics/animate-alpha.png", "animate", renderer))
    {
        return false;
    }

    gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
    gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));

    return true;
}

void Game::render()
{
    SDL_RenderClear(renderer);

    for(std::vector<GameObject*>::size_type i = 0; i != gameObjects.size(); i++)
    {
        gameObjects[i]->draw(renderer);
    }

    SDL_RenderPresent(renderer);
}

void Game::update()
{
    for(std::vector<GameObject*>::size_type i = 0; i != gameObjects.size(); i++)
    {
        gameObjects[i]->update();
    }
}

void Game::handleEvents()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT: // Click on cross for close the window
            _running = false;
            break;
        
        default:
            break;
        }
    }
}

void Game::clean()
{
    std::cout << "Cleaning game\n";
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool Game::running()
{
    return _running;
}

SDL_Renderer* Game::getRenderer() const { return renderer; }
