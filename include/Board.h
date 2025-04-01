#pragma once
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Button.H>

class Board {
private:
    Fl_Window* window;
    Fl_Button* surrenderButton; //por ahora solo cierra el juego
    Fl_Button* menuButton;

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

    
};