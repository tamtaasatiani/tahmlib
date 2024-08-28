#include "seek.h"

extern Tahm tahm;


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
	audio->setupDevice();
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
}


void Tahm::destroy(void)
{
	SDL_DestroyRenderer(renderer->SDLrenderer);

	SDL_DestroyWindow(window->SDLwindow);

	SDL_Quit();
}