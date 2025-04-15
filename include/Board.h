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
    Fl_Button* surrenderButton; //por ahora solo cierra el juego
    Fl_Button* menuButton;


    unordered_map<string, Fl_PNG_Image*> vesselSprites;

    bool surrender;
    bool goMenu;

    static void clickSurrender(Fl_Widget*, void* action);
    //static void clickMenu(Fl_Widget*, void* action);

    

public:
    Board();
    ~Board();

    void show();

    void hide();


    bool playerSurrender() const;

    void loadVessel();

    Fl_PNG_Image* getVesselImage(const string& vesselID);


};