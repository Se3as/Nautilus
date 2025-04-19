#include "Game.h"
#include "Player.h"
#include <Fl/Fl.H>
#include <fstream>

Game::Game() {
    music.toThePlaylist("assets/sfx/Barotrauma OST_ Embrace the Abyss (Menu Theme).mp3");
    //music.toThePlaylist();
    //music.play();
}

void Game::run(){
    
    menu.show();

    while(!menu.shouldStartGame() && !menu.shouldQuitGame()){
        Fl::wait();
    }

    if (!menu.shouldQuitGame()) {

        board.createPlayers();
        board.show();
    } else {
        board.endWarMode();
    }
    

    while(!board.warMode()){
        
        cout<<"jugador ";
        cout<<board.getPlayer();
        cout<<" en turno" <<endl;

        board.hudHide(board.getPlayer());
        board.terrainVeil(board.getPlayer());

        if(board.getPlayer() == 1){
            while(board.player1->getActions() > 0){
                if(board.warMode()){
                    board.hide();
                    break;
                }
                Fl::wait();
            }
            board.player1->refreshActions();
            board.player1->addCredits();

        } else if(board.getPlayer() == 2) {
            while(board.player2->getActions() > 0){
                if(board.warMode()){
                    board.hide();
                    break;
                }
                Fl::wait();
            }
            board.player2->refreshActions();
            board.player2->addCredits();
        }

        board.swapPlayer();

        Fl::wait();
    }

    Fl::run();
}