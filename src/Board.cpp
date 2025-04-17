#include "Board.h"
#include "Player.h"

#define BUYDECOY 1
#define BUYUPGRADEPOINTS 2
#define BUYSPIES 3
#define BUYVESSEL 4
#define BUYTYPHON 5
#define BUYDONG 6
#define BUYCAMEL 7
#define BUYREMORA 8
#define BUYWINTERHALTER 9

Board::Board() : window(nullptr), surrenderButton(nullptr), menuButton(nullptr), surrender(false), goMenu(false), docking(false){
    
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
    moneyButton1->callback(money1Click, this);
    moneyButton2 = new Fl_Button(1150, 208, moneyIcon->w(), moneyIcon->h());
    moneyButton2->image(moneyIcon);
    moneyButton2->box(FL_NO_BOX);
    moneyButton2->callback(money2Click, this);

    Fl_PNG_Image* decoy_icon = new Fl_PNG_Image("assets/gfx/ui/Decoy_Icon.png");
    Fl_Image* decoyIcon = decoy_icon->copy(50, 50);
    delete decoy_icon;
    decoyButton1 = new Fl_Button(5, 278, decoyIcon->w(), decoyIcon->h());
    decoyButton1->image(decoyIcon);
    decoyButton1->box(FL_NO_BOX);
    decoyButton1->callback(decoy1Click, this);
    decoyButton2 = new Fl_Button(1150, 278, decoyIcon->w(), decoyIcon->h());
    decoyButton2->image(decoyIcon);
    decoyButton2->box(FL_NO_BOX);
    decoyButton2->callback(decoy2Click, this);

    Fl_PNG_Image* upgrade_icon = new Fl_PNG_Image("assets/gfx/ui/Upgrade_Icon.png");
    Fl_Image* upgradeIcon = upgrade_icon->copy(50, 50);
    delete upgrade_icon;
    upgradeButton1 = new Fl_Button(5, 340, upgradeIcon->w(), upgradeIcon->h());
    upgradeButton1->image(upgradeIcon);
    upgradeButton1->box(FL_NO_BOX);
    upgradeButton1->callback(upgrade1Click, this);
    upgradeButton2 = new Fl_Button(1150, 340, upgradeIcon->w(), upgradeIcon->h());
    upgradeButton2->image(upgradeIcon);
    upgradeButton2->box(FL_NO_BOX);
    upgradeButton2->callback(upgrade2Click, this);

    Fl_PNG_Image* spies_icon = new Fl_PNG_Image("assets/gfx/ui/Spies_Icon.png");
    Fl_Image* spiesIcon = spies_icon->copy(50, 50);
    delete spies_icon;
    spiesButton1 = new Fl_Button(5, 410, spiesIcon->w(), spiesIcon->h());
    spiesButton1->image(spiesIcon);
    spiesButton1->box(FL_NO_BOX);
    spiesButton1->callback(spies1Click, this);
    spiesButton2 = new Fl_Button(1150, 410, spiesIcon->w(), spiesIcon->h());
    spiesButton2->image(spiesIcon);
    spiesButton2->box(FL_NO_BOX);
    spiesButton2->callback(spies2Click, this);


    buyVenture1 = new Fl_Button(64, 150, 60, 30);
    buyVenture1->image(vesselSprites["venture"]);
    buyVenture1->box(FL_NO_BOX);
    buyVenture1->callback(venture1Click, this);

    buyTyphon1 = new Fl_Button(64, 220, 60, 30);
    buyTyphon1->image(vesselSprites["typhon"]);
    buyTyphon1->box(FL_NO_BOX);
    buyTyphon1->callback(typhon1Click, this);

    buyDugong1 = new Fl_Button(64, 286, 60, 30);
    buyDugong1->image(vesselSprites["dugong"]);
    buyDugong1->box(FL_NO_BOX);
    buyDugong1->callback(dugong1Click, this);

    buyCamel1 = new Fl_Button(64, 351, 60, 30);
    buyCamel1->image(vesselSprites["camel"]);
    buyCamel1->box(FL_NO_BOX);
    buyCamel1->callback(camel1Click, this);

    buyRemora1 = new Fl_Button(64, 421, 60, 30);
    buyRemora1->image(vesselSprites["remora"]);
    buyRemora1->box(FL_NO_BOX);
    buyRemora1->callback(remora1Click, this);

    buyWinterhalter1 = new Fl_Button(64, 491, 60, 30);
    buyWinterhalter1->image(vesselSprites["winterhalter"]);
    buyWinterhalter1->box(FL_NO_BOX);
    buyWinterhalter1->callback(winterhalter1Click, this);


    buyVenture2 = new Fl_Button(1078, 150, 60, 30);
    buyVenture2->image(vesselSprites["venture"]);
    buyVenture2->box(FL_NO_BOX);
    buyVenture2->callback(venture2Click, this);

    buyTyphon2 = new Fl_Button(1078, 220, 60, 30);
    buyTyphon2->image(vesselSprites["typhon"]);
    buyTyphon2->box(FL_NO_BOX);
    buyTyphon2->callback(typhon2Click, this);

    buyDugong2 = new Fl_Button(1078, 286, 60, 30);
    buyDugong2->image(vesselSprites["dugong"]);
    buyDugong2->box(FL_NO_BOX);
    buyDugong2->callback(dugong2Click, this);

    buyCamel2 = new Fl_Button(1078, 351, 60, 30);
    buyCamel2->image(vesselSprites["camel"]);
    buyCamel2->box(FL_NO_BOX);
    buyCamel2->callback(camel2Click, this);

    buyRemora2 = new Fl_Button(1078, 421, 60, 30);
    buyRemora2->image(vesselSprites["remora"]);
    buyRemora2->box(FL_NO_BOX);
    buyRemora2->callback(remora2Click, this);

    buyWinterhalter2 = new Fl_Button(1078, 491, 60, 30);
    buyWinterhalter2->image(vesselSprites["winterhalter"]);
    buyWinterhalter2->box(FL_NO_BOX);
    buyWinterhalter2->callback(winterhalter2Click, this);



    //ajustar tama;o del grid luego
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {

        int posX = axisX + col * (buttonSize + deadSpace);
        int posY = axisY + row * (buttonSize + deadSpace);

        terrainNodes[row][col] = new Terrain(row, col);

        terrainGrid[row][col] = new Fl_Button(posX, posY, buttonSize, buttonSize);

        TerrainPosition* location = new TerrainPosition{row, col};

        terrainGrid[row][col]->callback(terrainClick, location);
        }
    }


    window->user_data(this);

}


void Board::createPlayers() {
    player1 = new Player(1);
    player2 = new Player(2);
    this->player1StartCol = 0;
    this->player1EndCol = cols / 2;
    this->player2StartCol = cols / 2;
    this->player2EndCol = cols;
}

//ADDING ALEX
/* Pienso que ya no es necesario el ID
int Board::whoIsPlayer(int ID) {
    return Player::getPlayerID();
}*/


void Board::dockingMode() {
    docking = true;
}

void Board::abortDocking() {
    docking = false;
}

void Board::attackingMode() {
    attacking = true;
}

void Board::abortAttaking() {
    attacking = false;
}

void Board::spyingMode(){
    spying = true; 
}

void Board::abortSpying(){
    spying = false;
}

void Board::upgradingMode(){
    upgrading = true;
}

void Board::abortUpgrading(){
    upgrading = false;
}

void Board::decoyingMode(){
    decoying = true;
}
void Board::abortDecoying(){
    decoying = false;
}

void Board::deactivateModes(){
    abortDocking();
    abortAttaking();
    abortSpying();
    abortUpgrading();
    abortDecoying();
}

void Board::setVesselClicked(string nameVessel){
    vesselClicked = nameVessel;
}

string Board::getVesselClicked(){
    return vesselClicked;
}

void Board::setDamage(int d){
    damage = d;
}

int Board::getDamage(){
    return damage;
}

void Board::terrainClick(Fl_Widget* widget, void* actioned) {
    TerrainPosition* location = static_cast<TerrainPosition*>(actioned);
    Board* board = static_cast<Board*>(widget->parent()->user_data());
    
    Terrain* terrain = board->terrainNodes[location->longitude][location->latitude];

    Fl_Button* triggeredButton = static_cast<Fl_Button*>(widget);


    if(board->docking == true){
        string vesselClicked = board->getVesselClicked();
        Fl_Image* sprite = board->vesselSprites[vesselClicked]->copy(41, 20);
        triggeredButton->image(sprite);
        triggeredButton->redraw();
        terrain->setVessel(vesselClicked);
        terrain->setOccupied();
        board->callPirates(terrain);
        board->abortAttaking();
        board->abortDocking();
        //cout<<"Aqui1"<<endl;
        return;
    } else if(board->spying){
        return;
    }
    else if(board->upgrading && terrain->isOccupied()){
        board->callUpgrade(terrain);
        board->abortUpgrading();
        return;
    }
    else if(board->decoying && !terrain->isOccupied()){
        return;
    }else if(board->attacking && terrain->isOccupied()){
        //cout<<"Aqui3"<<endl;
        terrain->shooted(board->getDamage());
        terrain->terrainUnderFire();
        board->abortAttaking();
        board->setDamage(0);
        return;
    }
    else if(terrain->isOccupied()){
            //cout<<"Aqui2"<<endl;
            int damage = board->callAttack(terrain);
            board->setDamage(damage);
            board->attackingMode();
            return;
    }
     else{
        triggeredButton->color(FL_BLUE);
        triggeredButton->redraw();
    }


    // Aquí puedes acceder a la posición con pos->row y pos->col
    // y hacer lo que necesites con esa información
    
    //COMO USAR: creas un Fl_Button* triggeredButton = static_cast<Fl_Button*>(widget);
    //luego puedes meter logica en triggered button, ejemplo abajo


}

// Verificar la posicion si es valida, será necesario???
/*
int Board::isPositionValid(int row, int col) {
    int positionValid = 0;
    if (board->player1->myTurn(1) == true) {  // player 1 board side
      positionValid = (int) (0 <= row && 0 <= player1StartCol && row < rows 
        && col < player1EndCol);
    } else {  // player 2 board side
      positionValid = (int) (0 <= row && 0 <= player2StartCol && row < rows 
        && col < player2EndCol);
    }
    return positionValid;
}*/

// Verificar la posicion del ataque es valido, será necesario???
/*
int Board::attackPositionValid(int row, int col) {
    int attackPositionValid = 0;
    if (board->player1->myTurn(1) == true) {  // attack player 2 board side
      attackPositionValid = (int) (0 <= row && 0 <= player2StartCol && row < rows 
        && col < player2EndCol);
    } else {  // attack player 1 board side
      attackPositionValid = (int) (0 <= row && 0 <= player1StartCol && row < rows 
        && col < player1EndCol);
    }
    return attackPositionValid;
}*/

//CLICK PARA LOS BOTONES DE ACCION
void Board::money1Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->deactivateModes();
    // Mostrar la cantidad de dinero del jugador 1
    if (board->player1->myTurn(1)) {
        // Muestra el resultado en el terminal, falta implementarlo como label
        board->player1->showCoins();
    }
}

void Board::money2Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->deactivateModes();
    // Mostrar la cantidad de dinero del jugador 2
    if (board->player2->myTurn(2)) {
        // Muestra el resultado en el terminal, falta implementarlo como label
        board->player2->showCoins();
    }
}

void Board::decoy1Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->deactivateModes();
    int cost = 1;
    if (board->player1->myTurn(1) && board->player1->purchaseCalc(cost)) {
        board->decoyingMode();
    }
}

void Board::decoy2Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->deactivateModes();
    int cost = 1;
    if (board->player2->myTurn(2) && board->player2->purchaseCalc(cost)) {
        board->decoyingMode();
    }
}

void Board::upgrade1Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->deactivateModes();
    int cost = 2;
    if (board->player1->myTurn(1) && board->player1->purchaseCalc(cost)) {
        board->upgradingMode();
    }
}

void Board::upgrade2Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->deactivateModes();
    int cost = 2;
    if (board->player2->myTurn(2) && board->player2->purchaseCalc(cost)) {
        board->upgradingMode();
    }
}

void Board::spies1Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->deactivateModes();
    int cost = 3;
    if (board->player1->myTurn(1) && board->player1->purchaseCalc(cost)) {
        board->spyingMode();
    }
}

void Board::spies2Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->deactivateModes();
    int cost = 3;
    if (board->player2->myTurn(2) && board->player2->purchaseCalc(cost)) {
        board->spyingMode();
    }
}

//CLICKS PARA LOS BOTONES DE SUBMARINOS
void Board::venture1Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
  
    //Vessel* newVenture = new Vessel(venture, 100, 3);
    board->setVesselClicked("venture");
    board->deactivateModes();
    int cost = 4;
    if (board->player1->myTurn(1) && board->player1->purchaseCalc(cost)) {
        board->dockingMode();
    }
}

void Board::venture2Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);

    board->setVesselClicked("venture");
    board->deactivateModes();
    int cost = 4;
    if (board->player2->myTurn(2) && board->player2->purchaseCalc(cost)) {
        board->dockingMode();
    }
}

void Board::typhon1Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->setVesselClicked("typhon");
    board->deactivateModes();
    int cost = 5;
    if (board->player1->myTurn(1) && board->player1->purchaseCalc(cost)) {
        board->dockingMode();
    }
}

void Board::typhon2Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->setVesselClicked("typhon");
    board->deactivateModes();
    int cost = 5;
    if (board->player2->myTurn(2) && board->player2->purchaseCalc(cost)) {
        board->dockingMode();
    }
}

void Board::dugong1Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->setVesselClicked("dugong");
    board->deactivateModes();
    int cost = 6;
    if (board->player1->myTurn(1) && board->player1->purchaseCalc(cost)) {
        board->dockingMode();
    }
}

void Board::dugong2Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->setVesselClicked("dugong");
    board->deactivateModes();
    int cost = 6;
    if (board->player2->myTurn(2) && board->player2->purchaseCalc(cost)) {
        board->dockingMode();
    }
}

void Board::camel1Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->setVesselClicked("camel");
    board->deactivateModes();
    int cost = 7;
    if (board->player1->myTurn(1) && board->player1->purchaseCalc(cost)) {
        board->dockingMode();
    }
}

void Board::camel2Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->setVesselClicked("camel");
    board->deactivateModes();
    int cost = 7;
    if (board->player2->myTurn(2) && board->player2->purchaseCalc(cost)) {
        board->dockingMode();
    }
}

void Board::remora1Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->setVesselClicked("remora");
    board->deactivateModes();
    int cost = 8;
    if (board->player1->myTurn(1) && board->player1->purchaseCalc(cost)) {
        board->dockingMode();
    }
}

void Board::remora2Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->setVesselClicked("remora");
    board->deactivateModes();
    int cost = 8;
    if (board->player2->myTurn(2) && board->player2->purchaseCalc(cost)) {
        board->dockingMode();
    }
}

void Board::winterhalter1Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->setVesselClicked("winterhalter");
    board->deactivateModes();
    int cost = 9;
    if (board->player1->myTurn(1) && board->player1->purchaseCalc(cost)) {
        board->dockingMode();
    }
}

void Board::winterhalter2Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->setVesselClicked("winterhalter");
    board->deactivateModes();
    int cost = 9;
    if (board->player2->myTurn(2) && board->player2->purchaseCalc(cost)) {
        board->dockingMode();
    }
}

void Board::callPirates(Terrain* terrain){
    unordered_set<int> initial_elements;
    int iterations = 0;
    for(int i = 1; i < 101; i++){ 
        initial_elements.insert(i);                                         
    }
    for(int i = 1; i < 101; i++){
        int num = rand() % 100 + 1;
        while (initial_elements.find(num) == initial_elements.end()) {
            num = rand() % 100 + 1; 
        }
        terrain->sendPirates(num,iterations);
        //register_insert(iterations,terrain->getName());
        iterations = 0;
    }
}

int Board::callAttack(Terrain* terrain){
    int iterations = 0;
    terrain->callAttack(iterations);
    double damage = 100/(double)iterations;
    //register_search(iterations, terrain->getName(), damage);
    iterations = 0;
    return (int) damage;
}
void Board::callUpgrade(Terrain* terrain){
    int upPoints = 100; // Arreglar con upPoints de player
    int iterations = 0;
    if(terrain->callUpgrade(iterations,upPoints)){
        //register_remove(iterations, terrain->getName());
        iterations=0;
        for(int i=0; i < 29; i++){
            terrain->callUpgrade(iterations,upPoints);
            cout<<iterations<<endl;
            //register_remove(iterations, terrain->getName());
            iterations = 0;
        }
    }
    iterations=0;
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

void Board::clickSurrender(Fl_Widget*, void* actioned){
    Board* board = static_cast<Board*>(actioned);
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

// Mostrar la mitad del board
// Todavía falta terminar por revisar el código
/*
void Board::showBoard(Board *board, bool Player::playerID) {
    if (Player::playerID == 0) {
      for (int i = 0; i < rows; ++i) {
        for (int j = player1StartCol; j < player1EndCol; ++j) {
          window->show(node[i][j]);
        }
      }
    } else {
      for (int i = 0; i < rows; ++i) {
        for (int j = player2StartCol; j < player2EndCol; ++j) {
          window->show(node[i][j]);
        }
      }
    }
}

// Ocultar la mitad del board
// Todavía falta terminar por revisar el código
void Board::hideBoard(Board *board, bool Player::playerID) {
    if (Player::playerID == 0) {
      for (int i = 0; i < rows; ++i) {
        for (int j = player1StartCol; j < player1EndCol; ++j) {
          if (node[i][j].isNodeVessel()) {
            // Vessel detected
            Vessel* vessel;
            if(node[i][j].vesselUnderAttack(vessel)) {
              window->show(node[i][j]);
            } 
          } else {
            window->hide(node[i][j]);
          }      
        }
      }
    } else {
      for (int i = 0; i < rows; ++i) {
        for (int j = player2StartCol; j < player2EndCol; ++j) {
          if (node[i][j].isNodeVessel()) {
            // Vessel detected
            Vessel* vessel;
            if(node[i][j].vesselUnderAttack(vessel)) {
              window->show(node[i][j]);
            } 
          } else {
            window->hide(node[i][j]);
          }
        }
      }
    }
}
*/

Board::~Board(){
    if(window) {
        window->hide();  
        delete window; 
    }
}