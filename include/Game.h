#pragma once
//includes para el juego
#include "Menu.h"
#include "Board.h"
#include "Music.h"
#include "Postgame.h"

class Game {
private:
    Music music;
    Menu menu;
    Board board;
    Postgame postgame;
    
    int rounds;
    int turn;
    
public:
    Game();
    void run();

};