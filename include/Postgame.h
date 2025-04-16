#pragma once
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Button.H>

class Postgame {

private:
    Fl_Window* window;

    Fl_Button* justQuitButton;
    Fl_Button* goMenuButton;
    //quiza agregar algo para save results?

    bool goMenu;
    bool justQuit;

    static void clickJustQuit(Fl_Widget*, void* action);
    static void clickGoMenu(Fl_Widget*, void* action);

public:
    Postgame();
    ~Postgame();

    void show();
    void hide();

};