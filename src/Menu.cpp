#include "Menu.h"
#include <Fl/Fl_JPEG_Image.H>
#include <Fl/Fl_Box.H>

Menu::Menu() : window(nullptr), playButton(nullptr), quitButton(nullptr), startGame(false), quitGame(false){
    
    window = new Fl_Window(960, 540, "Menu");
    
    Fl_JPEG_Image* nauti_menu3 = new Fl_JPEG_Image("assets/gfx/backgrounds/nauti_menu3.jpg");
    Fl_Image* menuQHD = nauti_menu3->copy(960, 540);
    delete nauti_menu3;
    Fl_Box* menuBg = new Fl_Box(0, 0, menuQHD->w(), menuQHD->h());
    menuBg->image(menuQHD);

    Fl_JPEG_Image* play_button = new Fl_JPEG_Image("assets/gfx/ui/play_button.jpg");
    Fl_Image* buttonPlay = play_button->copy(150, 40);
    delete play_button;
    playButton = new Fl_Button(400, 400, buttonPlay->w(), buttonPlay->h());
    playButton->image(buttonPlay);
    playButton->callback(clickPlay, this);

    Fl_JPEG_Image* quit_button = new Fl_JPEG_Image("assets/gfx/ui/quit_button.jpg");
    Fl_Image* buttonQuit = quit_button->copy(150, 40);
    delete quit_button;
    quitButton = new Fl_Button(400, 450, buttonQuit->w(), buttonQuit->h());

    //esto hace que el boton sea transparente
    //quitButton->box(FL_NO_BOX);
    //quitButton->clear_visible_focus();

    quitButton->image(buttonQuit);
    quitButton->callback(clickQuit, this);

}

void Menu::clickPlay(Fl_Widget*, void* action){
    Menu* menu = static_cast<Menu*>(action);
    menu->startGame = true;
    menu->window->hide();
}

void Menu::clickQuit(Fl_Widget*, void* action){
    Menu* menu = static_cast<Menu*>(action);
    menu->quitGame = true;
    menu->window->hide();
}

void Menu::show(){ 
    window->show(); 
}

void Menu::hide(){
    window->hide();
}


bool Menu::shouldStartGame() const{ 
    return startGame; 
}

bool Menu::shouldQuitGame() const{
    return quitGame;
}


Menu::~Menu(){ 
    if(window) {
        window->hide();  
        delete window; 
    }
}