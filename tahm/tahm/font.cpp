#include "seek.h"

Tahm::Graphics::Font::Font(void)
{

	if (TTF_Init() < 0)
	{
		std::cout << "Error initializing SDL_ttf: " << TTF_GetError() << std::endl;
	}
}


TTF_Font* Tahm::Graphics::Font::newFont(const char* path, int size)
{
	TTF_Font* font = TTF_OpenFont(path, size);

	if (!font) {
		std::cout << "Failed to load font: " << TTF_GetError() << std::endl;
	}

	return font;
}
