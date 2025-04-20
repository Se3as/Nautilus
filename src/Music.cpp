#include "Music.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>

Music::Music() : track1(nullptr), track2(nullptr), performing(false), channel(1) {
    
    SDL_Init(SDL_INIT_AUDIO);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    performing = true;

}

void Music::toThePlaylist(const std::string& path) {

    if(!track1){
        track1 = Mix_LoadMUS(path.c_str());
    } else if(!track2) {
        track2 = Mix_LoadMUS(path.c_str());
    }
}

void Music::play(int loops) {

    if(channel == 1){
        Mix_PlayMusic(track1, loops);
        //cout<<"puse la cancion 1"<<endl;
    } else if(channel == 2){
        Mix_PlayMusic(track2, loops);
        //cout<<"puse la cancion 2"<<endl;
    }
}

void Music::switchTrack(){
    stop();
    //cout<<"detuve la cancion de menu"<<endl;
    if(channel == 1){
        channel = 2;
        //cout<<"cambie a track 2"<<endl;
    } else if(channel == 2){
        channel = 1;
        //cout<<"cambie a track 1"<<endl;
    }
    play();
    // cout<<"puse la cancion nueva"<<endl;
}

void Music::stop() {
    if (performing) {
        Mix_HaltMusic();
    }
}

Music::~Music() {
    stop();

    if (track1) {
        Mix_FreeMusic(track1);
        track1 = nullptr;
    }
    if (track2) {
        Mix_FreeMusic(track2);
        track2 = nullptr;
    }
    if (performing) {
        Mix_CloseAudio();
        SDL_Quit();
    }
}