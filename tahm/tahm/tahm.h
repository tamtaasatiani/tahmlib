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
	
private:	// classes
	// tahm's window. made up of
	// the SDL window + methods and parameters for it
	class Window
	{
	public: // attributes
		SDL_Window* SDLwindow;

	public:	// methods
		// should get called in "start". passes a reference to
		// the desired window title, width, and height,
		// which is later used by void init to initialize a 
		// window with the desired parameters.
		void create(const char* title, int width, int height);

	private: // attributes
		const char* title = "Untitled";

		int width = 400;
		int height = 400;

		int flags = 0;

	private: // methods
		// initialize a window, pass a reference inside the SDLwindow
		void init(void); // todo: encapsulate

		friend class Tahm;
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
	public:	// attributes
		int flags = SDL_RENDERER_ACCELERATED;

		// pointer that points to the engine's window
		Window* window;
		SDL_Renderer* SDLrenderer;

	public: // methods
		// creates a reference to the game window
		Renderer(Window& window);

	private: // methods
		// initialize renderer
		void init(void); // todo: encapsulate


		// prepare a default scene to render - blank black screen
		// called before the "draw" function
		void prepare(void); // todo: encapsulate

		// present the rendered scene to the renderer
		void present(void);	// todo: encapsulate

		friend class Tahm;
	};

public:	// classes
	// functions and methods associated with rendering
	// used by the developer for rendering different objects
	class Graphics
	{
	public:	// classes
		class Font
		{
		public: // methods
			Font();

			// create new font
			TTF_Font* newFont(const char* path, int size);

		};

		// class for drawing shapes or images
		class Draw
		{
		private: // attributes 
			Renderer* renderer;
		public:	// methods
			Draw(Renderer& renderer);

			SDL_Rect rect(int x, int y, int width, int height);
		};

	public:	// attributes
		Draw* draw;
		Font* font;

	public: // methods
		Graphics(Renderer& renderer);
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

	private:	// attributes
		Renderer* renderer;

		// current active color
		Color color = { 0, 0, 0 };

	};

	// general class for audio management
	class Audio
	{
	public:	// classes
		// class for creating sound instances
		class Sound
		{
		private:	// attributes
			SDL_AudioSpec* spec;
			Uint8* waveStart;
			Uint32 waveLength;

			SDL_AudioDeviceID* device;

		public:	// methods
			Sound(const char* path, SDL_AudioSpec* spec);
			~Sound();

			void play();
		
		private:
			void linkDevice(SDL_AudioDeviceID& device); // todo: encapsulate. Needs friend

			friend class Audio;
		};

	public:	// methods
		Audio();

		// create a new sound
		Sound* newSound(const char* path);

	private:	// attributes
		SDL_AudioDeviceID device;	// todo: encapsulate. Needs friend
		SDL_AudioSpec spec;

	private:	// methods
		void setupDevice();

		friend class Tahm;
	};

public:	// attributes
	// instances to all of the nested classes
	Window* window;
	Input* input;
	Renderer* renderer;
	Graphics* graphics;
	Audio* audio;

public:	// methods
	static Tahm& getInstance();

	void run();

	void initializeCallbacks(
		void(*start)(), void(*input)(Event),
		void(*update)(), void(*draw)()
	);

	~Tahm();

private:	// attributes
	static Tahm* tahm;

	// callbacks
	void(*start_ptr)();
	void(*input_ptr)(Event);
	void(*update_ptr)();
	void(*draw_ptr)();
	// callbacks shouldn't be allowed to be called from the outside

	// update & render running
	bool running;

private:	// methods
	Tahm();
	void init(void); // todo: encapsulate

	void setup();		// todod: encapsulate
	void loop();		// todo: encapsulate
	void handleEvents();	// todo: encapsulate

	// destroy window, renderer, and quit the application
	void destroy();	// todo: encapsulate
	
};
