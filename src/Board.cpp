#include "Board.h"


Board::Board() : window(nullptr), surrenderButton(nullptr), menuButton(nullptr), surrender(false), goMenu(false){
    
    window = new Fl_Window(1280, 720, "Nautilus Game");

    loadVessel();


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


    Fl_PNG_Image* money_icon = new Fl_PNG_Image("assets/gfx/ui/Money_Icon.png");
    Fl_Image* moneyIcon = money_icon->copy(50, 50);
    delete money_icon;
    Fl_Box* moneyBox = new Fl_Box(5, 5, moneyIcon->w(), moneyIcon->h());
    moneyBox->image(moneyIcon);

    Fl_PNG_Image* decoy_icon = new Fl_PNG_Image("assets/gfx/ui/Decoy_Icon.png");
    Fl_Image* decoyIcon = decoy_icon->copy(50, 50);
    delete decoy_icon;
    Fl_Box* decoyBox = new Fl_Box(5, 75, decoyIcon->w(), decoyIcon->h());
    decoyBox->image(decoyIcon);

    Fl_PNG_Image* upgrade_icon = new Fl_PNG_Image("assets/gfx/ui/Upgrade_Icon.png");
    Fl_Image* upgradeIcon = upgrade_icon->copy(50, 50);
    delete upgrade_icon;
    Fl_Box* upgradeBox = new Fl_Box(5, 135, upgradeIcon->w(), upgradeIcon->h());
    upgradeBox->image(upgradeIcon);

    Fl_PNG_Image* spies_icon = new Fl_PNG_Image("assets/gfx/ui/Spies_Icon.png");
    Fl_Image* spiesIcon = spies_icon->copy(50, 50);
    delete spies_icon;
    Fl_Box* spiesBox = new Fl_Box(5, 207, spiesIcon->w(), spiesIcon->h());
    spiesBox->image(spiesIcon);





    

    Fl_PNG_Image* selkiepx800 = vesselSprites["selkie"];

    Fl_Image* selkie = selkiepx800->copy(62, 30);
    delete selkiepx800;
    Fl_Box* subBox = new Fl_Box(197, 220, 62, 30);
    subBox->image(selkie);





}


void::Board::loadVessel(){
    vesselSprites["selkie"] = new Fl_PNG_Image("assets/gfx/vessels/800px-Selkie.png");

    //cargar las imagenes de los demas submarinos
    //hacer resize de imagenes
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