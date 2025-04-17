#include "Game.h"
#include "Player.h"
#include <Fl/Fl.H>

Game::Game(){
    music.load("assets/sfx/Barotrauma OST_ Embrace the Abyss (Menu Theme).mp3");
    //music.play();
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

    // Crear jugadores
    board.createPlayers();
    bool start = true;
    rounds = 1;
    turn = 1;
    // Empezar el juego en el jugador 1
    // Todavía no sirve como el main del juego
    
    /*while (start) {
        int actions = 3;
        if (rounds == 1) {
            while(board.player1->myTurn(turn) && board.player1->getActionPoints() > 0) {
                // show player1 board
                // hide player2 board
                // solamente habilitar comprar submarinos
                
                cout << "Entre aqui player1 " << board.player1->getActionPoints() << endl;
                actions--;
                board.player1->setActionPoints(actions);
            }
            turn++;
            actions = 3;
            while(board.player2->myTurn(turn) && board.player2->getActionPoints() > 0) {
                // show player1 board
                // hide player2 board
                // solamente habilitar comprar submarinos
                cout << "Entre aqui player2 " << board.player2->getActionPoints() << endl;
                actions--;
                board.player2->setActionPoints(actions);
            }
            turn--;
            rounds++;
        }
        board.player1->setActionPoints(3);
        while(board.player1->myTurn(turn) && board.player1->getActionPoints() > 0) {
            // show player1 board
            // hide player2 board
            cout << "Entre aqui player1 " << board.player1->getActionPoints() << endl;
            actions--;
            board.player1->setActionPoints(actions); 
        }
        actions = 3;
        turn++;
        board.player1->setActionPoints(3);
        while(board.player2->myTurn(turn) && 
            board.player2->getActionPoints() > 0) {
            // show player1 board
            // hide player2 board
            cout << "Entre aqui player2 " << board.player2->getActionPoints() << endl;
            actions--;
            board.player2->setActionPoints(actions);
        }
        turn--;
        rounds++;
        if (rounds == 3) {
            break;
        }
    }*/

    // jugador atacante tipo de barco la operacion y las iteraciones 

    Fl::run();
}