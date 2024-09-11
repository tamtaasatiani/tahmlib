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
	renderer = new Renderer(window);

	input = new Input;
	graphics = new Graphics(renderer);
	audio = new Audio();
}

void Tahm::init(void)
{
	window->init();
	renderer->init();
	audio->init();
}

Tahm& Tahm::getInstance(void)
{
	if (tahm == nullptr) {
		tahm = new Tahm();
	}
	return *tahm;
}

/*

void Tahm::loop()
{
	//input->read();



	//if (update) update();
	//

	//input->clear();


	renderer->prepare();

	//if (draw) draw();

	renderer->present();

	SDL_Delay(16);
}*/

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
