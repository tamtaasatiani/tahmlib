#include "tahm.h"

/*
		tahmlib
		A C++ library for Game Development

		Author: Tamta Asatiani
		tamta@geolab.edu.ge

		-- Tahm --

		Definitions for the main tahmlib methods:
		setup, initialization, cleanup.
*/

Tahm* Tahm::tahm;

Tahm::Tahm(void)
{
	running = true;

	window = new Window;
	renderer = new Renderer(*window);

	input = new Input;
	graphics = new Graphics(*renderer);
	audio = new Audio();
}

void Tahm::init(vFunc start, vFunc update, vFunc draw, vFuncEv keypressed)
{
	callbackUpdate = update;
	callbackDraw = draw;
	callbackKeypressed = keypressed;

	start(); // Call Start right away
	window->init();
	renderer->init();
	audio->setupDevice();
}

Tahm& Tahm::getInstance(void)
{
	if (tahm == nullptr) {
		tahm = new Tahm();
	}
	return *tahm;
}

void Tahm::run()
{
	while(running)
	{
		// Update
		handleEvents();
		callbackUpdate();
		//Draw
		renderer->prepare();
		callbackDraw();
		renderer->present();

		SDL_Delay(16);
	}
}

void Tahm::handleEvents()
{
	Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				running = false;
				break;

			case SDL_KEYDOWN:
				callbackKeypressed(event);
				break;

			default:
				break;
		}
	}
}

Tahm::~Tahm()
{
	delete window, renderer;
	delete input, graphics, audio;
	delete tahm;
}


void Tahm::destroy(void)
{
	SDL_DestroyRenderer(renderer->SDLrenderer);

	SDL_DestroyWindow(window->SDLwindow);

	SDL_Quit();
}
