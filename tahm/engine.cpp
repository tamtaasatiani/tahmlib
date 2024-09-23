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

Tahm& tahm = Tahm::getInstance();

// game loop


int main(int argc, char* argv[])
{
	if (!GAME_FOUND)
	{
		std::cerr << "tahm cannot find the game code\n";
		return 0;
	}

	tahm.start_ptr = start;
	tahm.input_ptr = keypressed;
	tahm.update_ptr = update;
	tahm.draw_ptr = draw;

	tahm.run();

	return 0;
}