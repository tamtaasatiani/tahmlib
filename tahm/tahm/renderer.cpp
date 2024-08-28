#include "seek.h"


/*
        tahmlib
        A C++ library for Game Development

        Author: Tamta Asatiani
        tamta@geolab.edu.ge

        -- Renderer --

        Definitions for all methods
        used by the library renderer to set up the
        rendering process.
*/




Tahm::Renderer::Renderer(Window* window)
{
    this->window = window;
}

void Tahm::Renderer::init(void)
{
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    SDLrenderer = SDL_CreateRenderer(window->SDLwindow, -1, flags);

    if (!SDLrenderer)
    {
        std::cout << ("Failed to create renderer: %s\n", SDL_GetError()) << std::endl;
        exit(1);
    }
}



void Tahm::Renderer::prepare(void)
{
    SDL_SetRenderDrawColor(SDLrenderer, 0, 0, 0, 255);
    SDL_RenderClear(SDLrenderer);
}

void Tahm::Renderer::present(void)
{
    if (SDLrenderer == nullptr)
    {
        std::cout << ("SDL renderer not present\n", SDL_GetError());
        return;
    }

    SDL_RenderPresent(SDLrenderer);
}
