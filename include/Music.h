#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <string>

class Music {
private:
    Mix_Music* music;
    bool trackOn = false;

    
public:
    Music();
    ~Music();
    
    void toThePlaylist(const std::string& path);
    void play(int loops = -1);
    void stop();
};