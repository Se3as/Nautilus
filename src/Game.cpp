#include "Game.h"
#include "Player.h"
#include <Fl/Fl.H>

Game::Game(){
    music.toThePlaylist("assets/sfx/Barotrauma OST_ Embrace the Abyss (Menu Theme).mp3");
    //music.toThePlaylist();
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
    /*
    // Crear jugadores
    board.createPlayers();
    bool start = true;
    int actions = 3;
    int addCoins = 30;
    rounds = 1;
    turn = 1;
    // Empezar el juego en el jugador 1
    while (start) {
        if (rounds == 1) {
            board.player1->habilitateTurn();
            while(board.player1->myTurn(turn) && board.player1->getActionPoints() > 0) {
                // solamente habilitar comprar submarinos
            }
            turn++;
            board.player1->inhabilitateTurn();
            board.player2->habilitateTurn();
            while(board.player2->myTurn(turn) && board.player2->getActionPoints() > 0) {
                // solamente habilitar comprar submarinos
            }
            turn--;
            rounds++;
            board.player2->inhabilitateTurn();
        } else {
            board.player1->habilitateTurn();
            while(board.player1->myTurn(turn) && board.player1->getActionPoints() > 0) {
                board.player1->setActionPoints(actions);
            }
            board.player1->inhabilitateTurn();
            turn++;
            board.player2->habilitateTurn();
            while(board.player2->myTurn(turn) && board.player2->getActionPoints() > 0) {
                board.player2->setActionPoints(actions);
            }
            board.player2->inhabilitateTurn();
            turn--;
            rounds++;
        }
        if (rounds == 3) {
            break;
        }
        board.player1->addCoins(addCoins);
        board.player2->addCoins(addCoins);
    }
     */

    // jugador atacante tipo de barco la operacion y las iteraciones 

    Fl::run();
}