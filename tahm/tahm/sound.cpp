#include "seek.h"


Tahm::Audio::Sound::Sound(const char* path, SDL_AudioSpec* spec)
{


	spec = spec;

	if (SDL_LoadWAV(path, spec, &waveStart, &waveLength) == nullptr)
	{
		std::cout << ("Failed to load sound: %s\n", SDL_GetError()) << std::endl;
	}


}



void Tahm::Audio::Sound::linkDevice(SDL_AudioDeviceID* device)
{
	this->device = device;
}


Tahm::Audio::Sound::~Sound()
{
	SDL_FreeWAV(waveStart);
	SDL_CloseAudioDevice(*device);
}


void Tahm::Audio::Sound::play()
{
	int status = SDL_QueueAudio(*device, waveStart, waveLength);
	SDL_PauseAudioDevice(*device, 0);


}