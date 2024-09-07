#include "engine.h"



/*
		tahmlib
		A C++ library for Game Development

		Author: Tamta Asatiani
		tamta@geolab.edu.ge

		-- Game Loop --

		Sets up the game loop and creates conditions
		for breaking out of it, if specific requirements are met,
		and cleans up references when the application is closed.
*/




// event handling

void handleEvents()
{
	Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			Tahm::getInstance().running = false;
			break;


		case SDL_KEYDOWN:
			keypressed(event);
			break;

		default:
			break;
		}
	}

}


// game loop

int main(int argc, char* argv[])
{
	Tahm& tahm = Tahm::getInstance();
	start();
	tahm.init();




	while (tahm.running)
	{

		Event event;

		handleEvents();





		update();

		//render loop

		tahm.renderer->prepare();

		draw();

		tahm.renderer->present();

		SDL_Delay(16);
	}

	tahm.destroy();

	return 0;

}



