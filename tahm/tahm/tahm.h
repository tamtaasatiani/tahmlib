#pragma once

#include "seek.h"


/*
		tahmlib
		A C++ library for Game Development

		Author: Tamta Asatiani
		tamta@geolab.edu.ge

		-- Main Engine --

		Contains declarations for all of the methods and attributes
		provided in tahmlib.
*/




// engine class

class Tahm {

private:

	// tahm's window. made up of
	// the SDL window + methods and parameters for it
	class Window
	{
	private:
		const char* title = "Untitled";

		int width = 400;
		int height = 400;

		int flags = 0;

	public:
		SDL_Window* SDLwindow;

	public:

		// initialize a window, pass a reference inside the SDLwindow
		void init(void);

		// should get called in "start". passes a reference to the desired window title, width, and height,
		// which is later used by void init to initialize a window with the desired parameters
		void create(const char* title, int width, int height);

	};

	class Input
	{

	public:

		// holds a reference to the keyboard state
		const Uint8* keyPressed = SDL_GetKeyboardState(NULL);
	};


	// tahm's renderer. made up of
	// the SDL renderer + methods and parameters for it

	class Renderer
	{
	public:
		int flags = SDL_RENDERER_ACCELERATED;

		// pointer that points to the engine's window
		Window* window;
		SDL_Renderer* SDLrenderer;

	public:
		
		// creates a reference to the game window
		Renderer(Window* window);

		// initialize renderer
		void init(void);


		// prepare a default scene to render - blank black screen
		// called before the "draw" function
		void prepare(void);

		// present the rendered scene to the renderer
		void present(void);
	};

public:

	// functions and methods associated with rendering
	// used by the developer for rendering different objects

	class Graphics
	{
	public:
		class Font
		{
		public:

			Font();

			// create new font
			TTF_Font* newFont(const char* path, int size);

		};

	public:
		Graphics(Renderer* renderer);
		~Graphics();

		// fill the scene with a blank color
		// takes in arguments "red", "green", "blue", and "alpha" to determine the desired color
		void clear(int r, int g, int b, int a = 255);

		// set the drawing color. works like a state machine, tahm has an active color
		// takes in arguments "red", "green", "blue", and "alpha" to determine the desired color
		void setColor(int r, int g, int b, int a = 255);

		// draw text to screen
		// takes in arguments for the text position (x, y), font,
		// and the text that should be rendered
		void print(int x, int y, TTF_Font* font, const char* text);

		// draw text to screen and align it horizontally - left, center, or right
		// takes in arguments for the alignment style ('left', 'center', or 'right'),
		// alignment width, left and top margins, font,
		// and the text that should be rendered
		void printf(const char* alignment, int alignmentWidth, int marginX, int marginY, TTF_Font* font, const char* text);

		// class for drawing shapes or images

		class Draw
		{
		private:
			Renderer* renderer;
		public:
			Draw(Renderer* renderer);

			SDL_Rect rect(int x, int y, int width, int height);
		};

	private:
		Renderer* renderer;

	public:
		Draw* draw;
		Font* font;

	// current active color
	private:
		Color color = { 0, 0, 0 };
	};


	// general class for audio management

	class Audio
	{
	public:

		// class for creating sound instances

		class Sound
		{
		private:
			SDL_AudioSpec* spec;
			Uint8* waveStart;
			Uint32 waveLength;


			SDL_AudioDeviceID* device;

		public:
			Sound(const char* path, SDL_AudioSpec* spec);
			~Sound();

			void linkDevice(SDL_AudioDeviceID* device);

			void play();
		};

	public:
		Audio();

		void setupDevice();
		SDL_AudioDeviceID device;

		// create a new sound
		Sound* newSound(const char* path);

	private:
		SDL_AudioSpec spec;

	};




public:

	// instances to all of the nested classes
	Window* window;
	Input* input;
	Renderer* renderer;
	Graphics* graphics;
	Audio* audio;

	// update & render running
	bool running;

public:
	Tahm();
	~Tahm();


	void init(void);


	// destroy window, renderer, and quit the application
	void destroy();
};