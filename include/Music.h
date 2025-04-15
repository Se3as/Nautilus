#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <string>

class Music {
private:
    Mix_Music* music;
    bool isInitialized = false;
    
    
public:
    Music();
    ~Music();
    
    void load(const std::string& path);
    void play(int loops = -1);
    void stop();
};