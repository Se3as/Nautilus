#include "Music.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>

Music::Music() : music(nullptr) {
    if (SDL_Init(SDL_INIT_AUDIO) < 0 || Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "Audio init error: " << Mix_GetError() << std::endl;
        return;
    }
    isInitialized = true;
}

void Music::load(const std::string& path) {
    if (!isInitialized) return;
    music = Mix_LoadMUS(path.c_str());
    if (!music) std::cerr << "Failed to load music: " << Mix_GetError() << std::endl;
}

void Music::play(int loops) {
    if (music && isInitialized) Mix_PlayMusic(music, loops);
}

void Music::stop() {
    if (music && isInitialized) {
        Mix_HaltMusic();
        Mix_FreeMusic(music);
        music = nullptr;
    }
}

Music::~Music() {
    stop();
    if (isInitialized) {
        Mix_CloseAudio();
        SDL_Quit();
    }
}