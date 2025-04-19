#include "Game.h"
#include "Player.h"
#include <Fl/Fl.H>

Game::Game(){
    /*
    music.toThePlaylist("assets/sfx/Barotrauma OST_ Embrace the Abyss (Menu Theme).mp3");
    //music.toThePlaylist();
    music.play();*/
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

    // Crear jugadores
    board.createPlayers();
    bool start = true;
    int actions = 3;
    int addCoins = 30;
    rounds = 1;
    turn = 1;
    Fl_Widget* widget;
    // Empezar el juego en el jugador 1
    while (rounds <= 2) {
        if (rounds == 1) {
            // board.terrainVeil(widget, board.player1->getPlayerID());           
            board.player1->habilitateTurn();
            while(board.player1->myTurn() && board.player1->getActionPoints() > 0) {
                // Solamente comprar barcos
                Fl::wait();
            }
            turn++;
            board.player1->inhabilitateTurn();
            // board.terrainVeil(widget, board.player2->getPlayerID());
            board.player2->habilitateTurn();
            while(board.player2->myTurn() && board.player2->getActionPoints() > 0) {
                Fl::wait();
            }
            board.player2->inhabilitateTurn();
            turn--;
            rounds++;
        } else {
            // board.terrainVeil(widget, board.player1->getPlayerID());
            board.player1->habilitateTurn();
            board.player1->setActionPoints(actions);
            while(board.player1->myTurn() && board.player1->getActionPoints() > 0) {
                Fl::wait();
            }
            board.player1->inhabilitateTurn();
            turn++;
            // board.terrainVeil(widget, board.player2->getPlayerID());
            board.player2->habilitateTurn();
            board.player2->setActionPoints(actions);
            while(board.player2->myTurn() && board.player2->getActionPoints() > 0) {
                Fl::wait();
            }
            board.player2->inhabilitateTurn();
            turn--;
            rounds++;
        }
        board.player1->addCoins(addCoins);
        board.player2->addCoins(addCoins);
    }

    while(board.playerSurrender()) {
        postgame.show();
    }
    

    

    // jugador atacante tipo de barco la operacion y las iteraciones 

    Fl::run();
}