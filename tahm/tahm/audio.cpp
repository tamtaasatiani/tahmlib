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







Tahm::Audio::~Audio() {
	cleanUp();
}

bool Tahm::Audio::init()
{
	if (SDL_Init(SDL_INIT_AUDIO) < 0) {
		std::cerr << "Failed to init SDL Audio: " << SDL_GetError() << "\n";
		return false;
	}
	return true;
}

bool Tahm::Audio::loadWav(const std::string& id, const std::string& filepath) {
	SDL_AudioSpec* spec = new SDL_AudioSpec;
	Uint8* buffer;
	Uint32 length;

	if (SDL_LoadWAV(filepath.c_str(), spec, &buffer, &length) == nullptr) {
		std::cerr << "Failed to load Wav file \" " << filepath << "\": " << SDL_GetError() << "\n";
		delete spec;
		return false;
	}

	// using hashtable for storing all audio files
	sounds[id] = { spec, buffer, length };
	return true;
}

void Tahm::Audio::playWav(const std::string& id) {
	auto it = sounds.find(id);
	if (it != sounds.end()) {
		SDL_AudioSpec* spec = it->second.spec;
		Uint8* buffer = it->second.buffer;
		Uint32 length = it->second.length;

		if (audioDevice == 0) {
			audioDevice = SDL_OpenAudioDevice(nullptr, 0, spec, nullptr, SDL_AUDIO_ALLOW_ANY_CHANGE);
			if (audioDevice == 0) {
				std::cerr << "Failed to open audio device: " << SDL_GetError() << "\n";
				return;
			}
		}

		SDL_ClearQueuedAudio(audioDevice);

		if (SDL_QueueAudio(audioDevice, buffer, length) < 0) {
			std::cerr << "Failed to queue audio: " << SDL_GetError() << "\n";
			return;
		}

		SDL_PauseAudioDevice(audioDevice, 0);
	}
	else {
		std::cerr << "Sound ID not found: " << id << "\n";
	}
}

void Tahm::Audio::cleanUp() {
	for (auto& sound : sounds) {
		SDL_FreeWAV(sound.second.buffer);
		delete sound.second.spec;
	}
}