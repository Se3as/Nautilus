#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <string>
using namespace std;

class Music {
private:
    Mix_Music* track1;
    Mix_Music* track2;
    bool performing;
    int channel;

public:
    Music();
    ~Music();
    
    void toThePlaylist(const std::string& path);
    void play(int loops = -1);
    void switchTrack();
    void stop();
};