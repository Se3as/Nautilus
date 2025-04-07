#include "Game.h"
#include <Fl/Fl.H>

Game::Game(){
    music.load("assets/sfx/Barotrauma OST_ Embrace the Abyss (Menu Theme).mp3");
    music.play();
}

void Game::run(){
    menu.show();
    
    
    while(!menu.shouldStartGame() && !menu.shouldQuitGame()){
        Fl::wait();
    }
    
    if (!menu.shouldQuitGame()) {
        board.show();
        //Fl::run();
    }

    while(board.playerSurrender()){
        Fl::wait();
    }

    if(board.playerSurrender()){
        postgame.show();
    }



    // jugador atacante tipo de barco la operacion y las iteraciones 

    Fl::run();
}