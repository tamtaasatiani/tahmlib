#pragma once

#include "tahm/seek.h"




/*
		tahmlib
		A C++ library for Game Development

		Author: Tamta Asatiani
		tamta@geolab.edu.ge

		-- Methods --

		Main library methods that represent the game loop:
		start, update, render, and event.
*/


extern Tahm tahm;

// start method, get's called once at the start
void start();

// update method, gets called every frame
void update();

// draw method, gets called every frame after update. used for rendering
void draw();

// keypressed method, only called when there's an event, takes in an event as the argument
void keypressed(Event event);


int main(int argc, char* argv[]);