#include "Board.h"


Board::Board() : window(nullptr), surrenderButton(nullptr), menuButton(nullptr), surrender(false), goMenu(false){
    
    window = new Fl_Window(1280, 720, "Nautilus Game");

    loadVessel();

    Fl_JPEG_Image* nauti_map1 = new Fl_JPEG_Image("assets/gfx/backgrounds/nauti_map1.jpg");
    Fl_Image* background = nauti_map1->copy(1280, 720);
    delete nauti_map1;
    Fl_Box* bgBox = new Fl_Box(0, 0, background->w(), background->h());
    bgBox->image(background);

    Fl_PNG_Image* quit_button = new Fl_PNG_Image("assets/gfx/ui/Alien_Trinket.png");
    Fl_Image* buttonQuit = quit_button->copy(50, 50);
    delete quit_button;
    surrenderButton = new Fl_Button(1220, 278, buttonQuit->w(), buttonQuit->h());
    surrenderButton->image(buttonQuit);
    surrenderButton->box(FL_NO_BOX);
    surrenderButton->callback(clickSurrender, this);

    Fl_PNG_Image* linked_sign = new Fl_PNG_Image("assets/gfx/ui/Alien_Curio.png");
    Fl_Image* linkSign = linked_sign->copy(50, 50);
    delete linked_sign;
    Fl_Box* linkBox = new Fl_Box(1220, 340, linkSign->w(), linkSign->h());
    linkBox->image(linkSign);

    Fl_PNG_Image* money_icon = new Fl_PNG_Image("assets/gfx/ui/Money_Icon.png");
    Fl_Image* moneyIcon = money_icon->copy(50, 50);
    delete money_icon;
    moneyButton1 = new Fl_Button(5, 208, moneyIcon->w(), moneyIcon->h());
    moneyButton1->image(moneyIcon);
    moneyButton1->box(FL_NO_BOX);
    moneyButton2 = new Fl_Button(1150, 208, moneyIcon->w(), moneyIcon->h());
    moneyButton2->image(moneyIcon);
    moneyButton2->box(FL_NO_BOX);

    Fl_PNG_Image* decoy_icon = new Fl_PNG_Image("assets/gfx/ui/Decoy_Icon.png");
    Fl_Image* decoyIcon = decoy_icon->copy(50, 50);
    delete decoy_icon;
    decoyButton1 = new Fl_Button(5, 278, decoyIcon->w(), decoyIcon->h());
    decoyButton1->image(decoyIcon);
    decoyButton1->box(FL_NO_BOX);
    decoyButton2 = new Fl_Button(1150, 278, decoyIcon->w(), decoyIcon->h());
    decoyButton2->image(decoyIcon);
    decoyButton2->box(FL_NO_BOX);

    Fl_PNG_Image* upgrade_icon = new Fl_PNG_Image("assets/gfx/ui/Upgrade_Icon.png");
    Fl_Image* upgradeIcon = upgrade_icon->copy(50, 50);
    delete upgrade_icon;
    upgradeButton1 = new Fl_Button(5, 340, upgradeIcon->w(), upgradeIcon->h());
    upgradeButton1->image(upgradeIcon);
    upgradeButton1->box(FL_NO_BOX);
    upgradeButton2 = new Fl_Button(1150, 340, upgradeIcon->w(), upgradeIcon->h());
    upgradeButton2->image(upgradeIcon);
    upgradeButton2->box(FL_NO_BOX);

    Fl_PNG_Image* spies_icon = new Fl_PNG_Image("assets/gfx/ui/Spies_Icon.png");
    Fl_Image* spiesIcon = spies_icon->copy(50, 50);
    delete spies_icon;
    spiesButton1 = new Fl_Button(5, 410, spiesIcon->w(), spiesIcon->h());
    spiesButton1->image(spiesIcon);
    spiesButton1->box(FL_NO_BOX);
    spiesButton2 = new Fl_Button(1150, 410, spiesIcon->w(), spiesIcon->h());
    spiesButton2->image(spiesIcon);
    spiesButton2->box(FL_NO_BOX);


   
    //esto es para probar los vessels
    Fl_Box* subBox = new Fl_Box(197, 220, 62, 30);
    subBox->image(vesselSprites["selkie"]);


}

void::Board::loadVessel(){
    Fl_PNG_Image* selkiepx800 = new Fl_PNG_Image("assets/gfx/vessels/800px-Selkie.png");
    Fl_Image* selkie = selkiepx800->copy(62, 30);
    delete selkiepx800;
    vesselSprites["selkie"] = selkie;

    Fl_PNG_Image* azimuthpx800 = new Fl_PNG_Image("assets/gfx/vessels/800px-Azimuth.png");
    Fl_Image* azimuth = azimuthpx800->copy(62, 30);
    delete azimuthpx800;
    vesselSprites["azimuth"] = azimuth;

    Fl_PNG_Image* beriliapx800 = new Fl_PNG_Image("assets/gfx/vessels/800px-Berilia.png");
    Fl_Image* berilia = beriliapx800->copy(62, 30);
    delete beriliapx800;
    vesselSprites["berilia"] = berilia;

    Fl_PNG_Image* camelpx800 = new Fl_PNG_Image("assets/gfx/vessels/800px-Camel.png");
    Fl_Image* camel = camelpx800->copy(62, 30);
    delete camelpx800;
    vesselSprites["camel"] = camel;

    Fl_PNG_Image* dugongpx800 = new Fl_PNG_Image("assets/gfx/vessels/800px-Dugong.png");
    Fl_Image* dugong = dugongpx800->copy(62, 30);
    delete dugongpx800;
    vesselSprites["dugong"] = dugong;

    Fl_PNG_Image* kastrullpx800 = new Fl_PNG_Image("assets/gfx/vessels/800px-Kastrull.png");
    Fl_Image* kastrull = kastrullpx800->copy(62, 30);
    delete kastrullpx800;
    vesselSprites["kastrull"] = kastrull;

    Fl_PNG_Image* remorapx800 = new Fl_PNG_Image("assets/gfx/vessels/800px-Remora.png");
    Fl_Image* remora = remorapx800->copy(62, 30);
    delete remorapx800;
    vesselSprites["remora"] = remora;

    Fl_PNG_Image* typhonpx800 = new Fl_PNG_Image("assets/gfx/vessels/800px-Typhon.png");
    Fl_Image* typhon = typhonpx800->copy(62, 30);
    delete typhonpx800;
    vesselSprites["typhon"] = typhon;

    Fl_PNG_Image* venturepx800 = new Fl_PNG_Image("assets/gfx/vessels/800px-Venture.png");
    Fl_Image* venture = venturepx800->copy(62, 30);
    delete venturepx800;
    vesselSprites["venture"] = venture;

    Fl_PNG_Image* winterhalterpx800 = new Fl_PNG_Image("assets/gfx/vessels/800px-Winterhalter.png");
    Fl_Image* winterhalter = winterhalterpx800->copy(62, 30);
    delete winterhalterpx800;
    vesselSprites["winterhalter"] = winterhalter;
}

void Board::clickSurrender(Fl_Widget*, void* action){
    Board* board = static_cast<Board*>(action);
    board->surrender = true;
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