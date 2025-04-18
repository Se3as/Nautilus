#include "Music.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>

Music::Music() : music(nullptr) {
    
    SDL_Init(SDL_INIT_AUDIO);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    trackOn = true;

}

void Music::toThePlaylist(const std::string& path) {

    music = Mix_LoadMUS(path.c_str());

}

void Music::play(int loops) {

    Mix_PlayMusic(music, loops);

}

void Music::stop() {
    if (music && trackOn) {
        Mix_HaltMusic();
        Mix_FreeMusic(music);
        music = nullptr;
    }
}

Music::~Music() {
    stop();
    if (trackOn) {
        Mix_CloseAudio();
        SDL_Quit();
    }
}