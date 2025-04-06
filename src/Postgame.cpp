#include "Postgame.h"
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <Fl/Fl_Box.H>

//el problema es con la nueva window?
Postgame::Postgame(): goMenu(false), justQuit(false){

    window = new Fl_Window(854, 480, "Postgame Analisis");

    Fl_JPEG_Image* nauti_lose1 = new Fl_JPEG_Image("assets/gfx/backgrounds/nauti_lose1.jpg");
    Fl_Image* endgameBg = nauti_lose1->copy(854, 480);
    delete nauti_lose1;
    Fl_Box* endgameBox = new Fl_Box(0, 0, endgameBg->w(), endgameBg->h());
    endgameBox->image(endgameBg);

    
    Fl_PNG_Image* just_quit_button = new Fl_PNG_Image("assets/gfx/ui/Alien_Trinket.png");
    Fl_Image* buttonJustQuit = just_quit_button->copy(50, 50);
    delete just_quit_button;
    justQuitButton = new Fl_Button(400, 270, buttonJustQuit->w(), buttonJustQuit->h());
    justQuitButton->image(buttonJustQuit);
    justQuitButton->box(FL_NO_BOX);
    justQuitButton->callback(clickJustQuit, this);

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