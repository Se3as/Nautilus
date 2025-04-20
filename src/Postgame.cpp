#include "Postgame.h"


//el problema es con la nueva window?
Postgame::Postgame(): showQuit(false), endScreen(false){

    window = new Fl_Window(960, 540, "Analysis");
    //window->position(150,100);

    Fl_JPEG_Image* nauti_lose1 = new Fl_JPEG_Image("assets/gfx/backgrounds/nauti_lose1.jpg");
    Fl_Image* endgameBg = nauti_lose1->copy(window->w(), window->h());
    delete nauti_lose1;
    Fl_Box* endgameBox = new Fl_Box(0, 0, endgameBg->w(), endgameBg->h());
    endgameBox->image(endgameBg);


    Fl_JPEG_Image* just_quit_button = new Fl_JPEG_Image("assets/gfx/ui/quit_button.jpg");
    Fl_Image* buttonJustQuit = just_quit_button->copy(150, 40);
    delete just_quit_button;
    justQuitButton = new Fl_Button(380, 460, buttonJustQuit->w(), buttonJustQuit->h());
    justQuitButton->image(buttonJustQuit);
    justQuitButton->hide();
    justQuitButton->callback(clickJustQuit, this);
    
    //winner announcer
    results = new Fl_Box(365, 100, 0, 0, "WE ARE ALL WINNERS AT HEARTH...");
    results->labelcolor(fl_rgb_color(163, 202, 179));
    results->align(FL_ALIGN_RIGHT);
    results->labelsize(20);
    results->hide();
}


void Postgame::clickJustQuit(Fl_Widget*, void* action){
    Postgame* postgame = static_cast<Postgame*>(action);
    postgame->window->hide();
    postgame->endScreen = false;
}

void Postgame::endGame(int player){
    this->justQuitButton->show();
    endScreen = true;
    if(player == 1){
        this->results->copy_label("WINNER: PLAYER 1");
    } else if(player == 2){
        this->results->copy_label("WINNER: PLAYER 2");
    } else if(player == 0){
        this->results->copy_label("NO WINNER: DRAW");
    }
    this->results->show();
}


bool Postgame::postgameStatus(){
    return endScreen;
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