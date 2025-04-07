#pragma once
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Button.H>
#include <unordered_map>
#include <string>
#include <iostream>

#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <Fl/Fl_Box.H>

using namespace std;

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


    unordered_map<string, Fl_Image*> vesselSprites;

    bool surrender;
    bool goMenu;

    static void clickSurrender(Fl_Widget*, void* action);

    static void terrain11Click(Fl_Widget*, void* action);
    static void terrain12Click(Fl_Widget*, void* action);
    static void terrain13Click(Fl_Widget*, void* action);
    static void terrain14Click(Fl_Widget*, void* action);

public:
    Board();
    ~Board();

    void show();

    void hide();


    bool playerSurrender() const;

    void loadVessel();

    Fl_PNG_Image* getVesselImage(const string& vesselID);


};