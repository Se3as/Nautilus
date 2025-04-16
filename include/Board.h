#pragma once
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Button.H>
#include <unordered_map>
#include <string>
#include <iostream>

#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <Fl/Fl_Box.H>

#include "Player.h"

using namespace std;

struct TerrainPosition {
    
    //las filas horizontales
    int longitude;
    //las columnas veticales
    int latitude;
};

class Board {
private:
    Fl_Window* window;
    
    Fl_Button* surrenderButton; 
    Fl_Button* menuButton;
    Fl_Button* moneyButton1;
    Fl_Button* moneyButton2;
    Fl_Button* decoyButton1;
    Fl_Button* decoyButton2;
    Fl_Button* upgradeButton1;
    Fl_Button* upgradeButton2;
    Fl_Button* spiesButton1;
    Fl_Button* spiesButton2;

    Fl_Button* buyVenture1;
    Fl_Button* buyTyphon1;
    Fl_Button* buyDugong1;
    Fl_Button* buyCamel1;
    Fl_Button* buyRemora1;
    Fl_Button* buyWinterhalter1;

    Fl_Button* buyVenture2;
    Fl_Button* buyTyphon2;
    Fl_Button* buyDugong2;
    Fl_Button* buyCamel2;
    Fl_Button* buyRemora2;
    Fl_Button* buyWinterhalter2;

    Fl_Button* terrain11;
    Fl_Button* terrain12;
    Fl_Button* terrain13;
    Fl_Button* terrain14;

    //filas de la matriz   
    static const int rows = 8;
    //columnas de la matriz
    static const int cols = 12;

    Fl_Button* terrainGrid[rows][cols];

    unordered_map<string, Fl_Image*> vesselSprites;

    bool surrender;
    bool goMenu;

    static void clickSurrender(Fl_Widget*, void* action);

    //para manejar los clicks en el terreno
    static void terrainClick(Fl_Widget*, void* action);
    //datos de casillas
    const int buttonSize = 50;
    const int axisX = 300;
    const int axisY = 50;
    const int deadSpace = 5;

    static void money1Click(Fl_Widget*, void* action);
    static void money2Click(Fl_Widget*, void* action);

    static void decoy1Click(Fl_Widget*, void* action);
    static void decoy2Click(Fl_Widget*, void* action);

    static void upgrade1Click(Fl_Widget*, void* action);
    static void upgrade2Click(Fl_Widget*, void* action);

    static void spies1Click(Fl_Widget*, void* action);
    static void spies2Click(Fl_Widget*, void* action);


    static void venture1Click(Fl_Widget*, void* action);
    static void venture2Click(Fl_Widget*, void* action);

    static void typhon1Click(Fl_Widget*, void* action);
    static void typhon2Click(Fl_Widget*, void* action);

    static void dugong1Click(Fl_Widget*, void* action);
    static void dugong2Click(Fl_Widget*, void* action);

    static void camel1Click(Fl_Widget*, void* action);
    static void camel2Click(Fl_Widget*, void* action);

    static void remora1Click(Fl_Widget*, void* action);
    static void remora2Click(Fl_Widget*, void* action);

    static void winterhalter1Click(Fl_Widget*, void* action);
    static void winterhalter2Click(Fl_Widget*, void* action);


    //ADDING ALEX
    int whoIsPlayer(bool);



public:
    Board();
    ~Board();

    void show();

    void hide();


    bool playerSurrender() const;

    void loadVessel();

    Fl_PNG_Image* getVesselImage(const string& vesselID);


};