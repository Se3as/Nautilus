#include "Game.h"
#include <Fl/Fl.H>

Game::Game(){
    music.load("assets/sfx/Barotrauma OST_ Embrace the Abyss (Menu Theme).mp3");
    music.play();
}

void Game::run(){
    menu.show();
    
    //board.show();
    //Fl::run();

    while (!menu.shouldStartGame() && !menu.shouldQuitGame()) {
        Fl::wait();
    }
    
    if (!menu.shouldQuitGame()) {
        board.show();
        Fl::run();
    }
}