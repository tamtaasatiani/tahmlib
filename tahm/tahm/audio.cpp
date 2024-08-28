#include "seek.h"

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