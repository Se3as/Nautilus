#pragma once
#include <FL/Fl.H>
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Button.H>
#include <unordered_map>
#include <string>
#include <iostream>

#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <Fl/Fl_Box.H>

#include "Player.h"
#include "Terrain.h"
#include "log.h"

using namespace std;

struct TerrainPosition
{
    // las filas horizontales
    int longitude;
    // las columnas veticales
    int latitude;
};

class Board
{
private:
    Fl_Window* window;
    
    int player;

    int cost;

    Fl_Box *announcer;
    Fl_Box *playerLog;

    Fl_Button *surrenderButton;
    Fl_Button *menuButton;
    Fl_Button *healthButton1;
    Fl_Button *healthButton2;
    Fl_Button *moveButton1;
    Fl_Button *moveButton2;
    Fl_Button *moneyButton1;
    Fl_Button *moneyButton2;
    Fl_Button *decoyButton1;
    Fl_Button *decoyButton2;
    Fl_Button *upgradeButton1;
    Fl_Button *upgradeButton2;
    Fl_Button *spiesButton1;
    Fl_Button *spiesButton2;

    Fl_Button *buyVenture1;
    Fl_Button *buyTyphon1;
    Fl_Button *buyDugong1;
    Fl_Button *buyCamel1;
    Fl_Button *buyRemora1;
    Fl_Button *buyWinterhalter1;

    Fl_Button *buyVenture2;
    Fl_Button *buyTyphon2;
    Fl_Button *buyDugong2;
    Fl_Button *buyCamel2;
    Fl_Button *buyRemora2;
    Fl_Button *buyWinterhalter2;

    // filas de la matriz
    static const int rows = 8;
    // columnas de la matriz
    static const int cols = 12;

    Fl_Button *terrainGrid[rows][cols];

    // grid de nodos terreno
    Terrain *terrainNodes[rows][cols];

    // booleano para indicar que un barco esta siendo colocado o "atracado"
    Terrain *movingTerrain;
    bool inspect;
    bool docking;
    bool spying;
    bool upgrading;
    bool decoying;
    bool attacking;
    bool moving;
    string vesselClicked;
    int damage;
    unordered_map<string, Fl_Image *> vesselSprites;

    // puntero a log
    Log* log;

    bool surrender;
    bool defeat;

    bool goMenu;

    static void clickSurrender(Fl_Widget*, void* action);

    // para manejar los clicks en el terreno
    static void terrainClick(Fl_Widget *, void *action);
    // datos de casillas
    const int buttonSize = 61;
    const int axisX = 197;
    const int axisY = 68;
    const int deadSpace = 7;

    static void money1Click(Fl_Widget *, void *action);
    static void money2Click(Fl_Widget *, void *action);

    static void health1Click(Fl_Widget *, void *action);
    static void health2Click(Fl_Widget *, void *action);

    static void decoy1Click(Fl_Widget *, void *action);
    static void decoy2Click(Fl_Widget *, void *action);

    static void upgrade1Click(Fl_Widget *, void *action);
    static void upgrade2Click(Fl_Widget *, void *action);

    static void spies1Click(Fl_Widget *, void *action);
    static void spies2Click(Fl_Widget *, void *action);

    static void move1Click(Fl_Widget *, void *action);
    static void move2Click(Fl_Widget *, void *action);

    static void venture1Click(Fl_Widget *, void *action);
    static void venture2Click(Fl_Widget *, void *action);

    static void typhon1Click(Fl_Widget *, void *action);
    static void typhon2Click(Fl_Widget *, void *action);

    static void dugong1Click(Fl_Widget *, void *action);
    static void dugong2Click(Fl_Widget *, void *action);

    static void camel1Click(Fl_Widget *, void *action);
    static void camel2Click(Fl_Widget *, void *action);

    static void remora1Click(Fl_Widget *, void *action);
    static void remora2Click(Fl_Widget *, void *action);

    static void winterhalter1Click(Fl_Widget *, void *action);
    static void winterhalter2Click(Fl_Widget *, void *action);

    // Columnas delimitador de los jugadores
    int player1StartCol;
    int player1EndCol;
    int player2StartCol;
    int player2EndCol;
    
    //booleano que indica si hay ganador
    bool winner;

    public:

    Board();
    ~Board();

    void show();

    void hide();

    bool getSurrender();
    bool getDefeat();

    int whoWon(int round);

    bool verifyWinner();

    void terrainVeil(int player);

    void hudHide(int player);

    void swapPlayer();
    int getPlayer();

    // Atributos de los jugadores
    Player *player1;
    Player *player2;
    void createPlayers();

    // Buscar posicion valida
    int isPositionValid(Terrain* terrain);
    // buscar posicion valida del ataque
    int attackPositionValid(Terrain* terrain);

    void setVesselClicked(string nameVessel);

    string getVesselClicked();

    void setMovingTerrain(Terrain *mT);
    Terrain *getMovingTerrain();

    void inspectMode();

    void abortInspection();

    void dockingMode();

    void abortDocking();

    void attackingMode();

    void abortAttaking();

    string getDecoy();

    void spyingMode();
    void abortSpying();

    void upgradingMode();
    void abortUpgrading();

    void decoyingMode();
    void abortDecoying();

    Fl_Button* currentButton;
    void movingMode();
    void abortMoving();

    void deactivateModes();
    void setDamage(int d);

    int getDamage();

    bool warMode() const;

    void endWarMode();

    void callPirates(Terrain* terrain, int pirates);
    int callAttack(Terrain* terrain);
    void callUpgrade(Terrain* terrain);

    void loadVessel();

    Fl_PNG_Image *getVesselImage(const string &vesselID);
};