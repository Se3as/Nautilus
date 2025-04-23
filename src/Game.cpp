#include "Game.h"

Game::Game(): round(1) {
    music.toThePlaylist("assets/sfx/Barotrauma OST_ Embrace the Abyss (Menu Theme).mp3");
    music.toThePlaylist("assets/sfx/Barotrauma OST_ Subaquatic Symphony for Hammer and Metal (Lobby & Editor Music).mp3");
    music.play();
}

//game central loop manager
void Game::run(){
    
    menu.show();

    while(!menu.shouldStartGame() && !menu.shouldQuitGame()){
        Fl::wait();
    }

    if (!menu.shouldQuitGame()) {
        music.switchTrack();
        board.createPlayers();
        board.show();
    } else {
        board.endWarMode();
    }
    
    //veryfies none quit the game midway and exits if so
    while(!board.warMode()){

        cout<<"jugador ";
        cout<<board.getPlayer();
        cout<<" en turno" <<endl;

        board.hudHide(board.getPlayer());
        //cout<<" 1" <<endl;
        board.terrainVeil(board.getPlayer());
        //cout<<" 2" <<endl;
        if(board.getPlayer() == 1){
            while(board.player1->getActions() > 0){
                //cout<<" 4" <<endl;
                if(board.warMode()){
                    //cout<<" 5" <<endl;
                    board.hide();
                    //cout<<" 6" <<endl;
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

        round++;

        if(round > 2){
            if(board.verifyWinner()){
                board.endWarMode();
            }
        }

        board.swapPlayer();

        // this gives a second so that the player is able to see his last action
        Fl::check(); 
        sleep(1);

        postgame.show();

        //this waits 5 seconds for the second player to be on deck
        for(int timeframe = 5; timeframe > 0; --timeframe){
            if(board.warMode()){
                board.hide();
                break;
            }
            cout<<"Cambiando jugador en: "<< timeframe << endl;
            sleep(1);
            Fl::check(); 
        }

        postgame.hide();

        Fl::wait();
    }

    //if the game is finished this shows the results
    if(!postgame.postgameStatus()){
        if(board.getSurrender()){
            postgame.endGame(board.getPlayer());
        } else if(board.getDefeat()){
            postgame.endGame(board.whoWon(round));
        }
        
    }

    while(postgame.postgameStatus()){
        postgame.show();
        Fl::wait();
    }



    Fl::run();
}