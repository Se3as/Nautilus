#pragma once
//includes para el juego
#include "Menu.h"
#include "Board.h"
#include "Music.h"
#include "Postgame.h"
#include <fstream>

class Game {
private:
    Music music;
    Menu menu;
    Board board;
    Postgame postgame;
    
public:
    Game();
    void run();
};