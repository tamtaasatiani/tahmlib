#include "tahm/seek.h"
#include "engine.h"



/*
		Game Development library made with and for C++

		This code is a property of Tamta Asatiani
		tamta@geolab.edu.ge
*/











// engine instance

Tahm tahm = Tahm();


// event handling

void handleEvents()
{
	Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			tahm.running = false;
			break;


		case SDL_KEYDOWN:
			keypressed(event);
			break;

		default:
			break;
		}
	}

}


//game loop

int main(int argc, char* argv[])
{
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



