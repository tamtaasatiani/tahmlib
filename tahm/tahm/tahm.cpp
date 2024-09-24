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

void Tahm::init(void)
{
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
			input_ptr(event);
			break;

		default:
			break;
		}
	}

}

void Tahm::setup()
{
	start_ptr();
	init();
}

void Tahm::loop()
{
	handleEvents();

	update_ptr();

	renderer->prepare();

	draw_ptr();

	renderer->present();

	SDL_Delay(16);
}

void Tahm::run()
{
	setup();

	while (running)
	{
		loop();
	}

	destroy();

	return;
}

void Tahm::destroy(void)
{
	SDL_DestroyRenderer(renderer->SDLrenderer);

	SDL_DestroyWindow(window->SDLwindow);

	SDL_Quit();
}

Tahm::~Tahm()
{
	delete window;
	delete renderer;
	delete input; 
	delete graphics;
	delete audio;
	delete tahm;
}