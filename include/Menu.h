#pragma once
//includes para la ventana
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Button.H>
#include <FL/Fl_PNG_Image.H>

class Menu {

private:
    Fl_Window* window;
    Fl_Button* playButton;
    Fl_Button* quitButton;

    bool startGame;
    bool quitGame;

    static void clickPlay(Fl_Widget*, void* action);
    static void clickQuit(Fl_Widget*, void* action);

public:
    Menu();
    ~Menu();

    void show();
    void hide();

    //revisar este con el que esta en el Game.h
    bool shouldStartGame() const;
    bool shouldQuitGame() const;

};