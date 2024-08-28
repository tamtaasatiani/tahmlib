#include "seek.h"


/*
		tahmlib
		A C++ library for Game Development

		Author: Tamta Asatiani
		tamta@geolab.edu.ge

		-- Audio --

		Definitions for all audio related methods,
		such as: audio device management, sound creation.
*/








Tahm::Audio::Audio()
{
	SDL_Init(SDL_INIT_AUDIO);
}

void Tahm::Audio::setupDevice()
{
	device = SDL_OpenAudioDevice(nullptr, 0, &spec, nullptr, SDL_AUDIO_ALLOW_ANY_CHANGE);

	if (device == 0)
	{
		std::cout << "Sound device error: " << SDL_GetError() << std::endl;
	}
}



Tahm::Audio::Sound* Tahm::Audio::newSound(const char* path)
{
	Sound* sound = new Sound(path, &spec);
	sound->linkDevice(&device);
	return sound;
}