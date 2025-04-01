#include "Board.h"
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <Fl/Fl_Box.H>

Board::Board() : window(nullptr), surrenderButton(nullptr), menuButton(nullptr), surrender(false), goMenu(false){
    
    window = new Fl_Window(1280, 720, "Nautilus Game");

    Fl_JPEG_Image* nauti_map1 = new Fl_JPEG_Image("assets/gfx/backgrounds/nauti_map1.jpg");
    Fl_Image* background = nauti_map1->copy(1280, 720);
    delete nauti_map1;
    Fl_Box* bgBox = new Fl_Box(0, 0, background->w(), background->h());
    bgBox->image(background);


    Fl_JPEG_Image* quit_button = new Fl_JPEG_Image("assets/gfx/ui/quit_button.jpg");
    Fl_Image* buttonQuit = quit_button->copy(150, 40);
    delete quit_button;
    surrenderButton = new Fl_Button(400, 450, buttonQuit->w(), buttonQuit->h());
    surrenderButton->image(buttonQuit);
    surrenderButton->callback(clickSurrender, this);


    Fl_PNG_Image* selkiepx800 = new Fl_PNG_Image("assets/gfx/vessels/800px-Selkie.png");
    Fl_Image* selkie = selkiepx800->copy(62, 30);
    delete selkiepx800;
    Fl_Box* subBox = new Fl_Box(197, 220, 62, 30);
    subBox->image(selkie);
}

void Board::clickSurrender(Fl_Widget*, void* action){
    Board* board = static_cast<Board*>(action);
    board->surrender = true;
    
    //por ahora solo cierra el juego, arreglar para pantalla de resuotados

    board->window->hide();

}

bool Board::playerSurrender() const{
    return surrender;
}

void Board::show(){ 
    window->show(); 
}

void Board::hide(){
    window->hide();
}

Board::~Board(){
    if(window) {
        window->hide();  
        delete window; 
    }
}