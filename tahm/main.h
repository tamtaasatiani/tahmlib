#pragma once

#include "engine.h"

// start method, get's called once at the start
void start();

// update method, gets called every frame
void update();

// draw method, gets called every frame after update. used for rendering
void draw();

// keypressed method, only called when there's an event, takes in an event as the argument
void keypressed(Event event);
