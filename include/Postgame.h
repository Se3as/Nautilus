#pragma once
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Button.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <Fl/Fl_Box.H>

class Postgame {

private:
    Fl_Window* window;
    Fl_Button* justQuitButton;
    Fl_Box *results;

    bool showQuit;
    bool endScreen;

    static void clickJustQuit(Fl_Widget*, void* action);

public:
    Postgame();
    ~Postgame();

    void show();
    void hide();
    void endGame(int player);
    bool postgameStatus();
};