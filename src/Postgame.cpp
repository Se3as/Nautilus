#include "Postgame.h"
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <Fl/Fl_Box.H>

//el problema es con la nueva window?
Postgame::Postgame(): window(new Fl_Window(854, 480, "Postgame Analisis")){

    Fl_JPEG_Image* nauti_lose1 = new Fl_JPEG_Image("assets/gfx/backgrounds/nauti_lose1.jpg");
    Fl_Image* endgameBg = nauti_lose1->copy(854, 480);
    delete nauti_lose1;
    Fl_Box* endgameBox = new Fl_Box(0, 0, endgameBg->w(), endgameBg->h());
    endgameBox->image(endgameBg);

}

void Postgame::clickJustQuit(Fl_Widget*, void* action){
    Postgame* postgame = static_cast<Postgame*>(action);
    postgame->justQuit = true;
    postgame->window->hide();
}

void Postgame::clickGoMenu(Fl_Widget*, void* action){
    Postgame* postgame = static_cast<Postgame*>(action);
    postgame->goMenu = true;
    postgame->window->hide();
}

void Postgame::show(){ 
    window->show(); 
}

void Postgame::hide(){
    window->hide();
}

Postgame::~Postgame(){
    delete window;
}