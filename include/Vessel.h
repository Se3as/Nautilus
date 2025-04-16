#pragma once
//includes para la ventana
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Button.H>
#include <Fl/Fl_JPEG_Image.H>
#include <Fl/Fl_Box.H>
#include <unordered_map>
#include <string>
#include <iostream>

class Vessel {

private:
    Fl_Window* window;

    Fl_Button* attack;


    bool upgrading;
    bool weaponCooldown;




    static void clickAttack(Fl_Widget*, void* action);
    

public:
    Vessel();
    ~Vessel();

    void show();
    void hide();

    
    bool weaponOnCooldown() const;

};