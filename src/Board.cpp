#include "Board.h"

#define BUYDECOY 1
#define BUYUPGRADEPOINTS 2
#define BUYSPIES 3
#define BUYVESSEL 4
#define BUYTYPHON 5
#define BUYDONG 6
#define BUYCAMEL 7
#define BUYREMORA 8
#define BUYWINTERHALTER 9

//this is the game board. it instances all of its resources, meaning necesary buttons for player to action and progress in the game
Board::Board() : window(nullptr), player(1), cost(0), winner(false), surrenderButton(nullptr), menuButton(nullptr), 
surrender(false), defeat(false), goMenu(false), inspect(false), docking(false), attacking(false), spying(false),
upgrading(false), decoying(false),moving(false), movingTerrain(nullptr){ 
    log = new Log();
    log->openCsv();
    window = new Fl_Window(1280, 720, "Nautilus Game");
    
    loadVessel();

    Fl_JPEG_Image* nauti_map1 = new Fl_JPEG_Image("assets/gfx/backgrounds/nauti_map1.jpg");
    Fl_Image* background = nauti_map1->copy(window->w(), window->h());
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

    //actionable buttons for each player
    Fl_PNG_Image* money_icon = new Fl_PNG_Image("assets/gfx/ui/Money_Icon.png");
    Fl_Image* moneyIcon = money_icon->copy(50, 50);
    delete money_icon;
    moneyButton1 = new Fl_Button(5, 140, moneyIcon->w(), moneyIcon->h());
    moneyButton1->image(moneyIcon);
    moneyButton1->box(FL_NO_BOX);
    moneyButton1->callback(money1Click, this);
    moneyButton2 = new Fl_Button(1150, 140, moneyIcon->w(), moneyIcon->h());
    moneyButton2->image(moneyIcon);
    moneyButton2->box(FL_NO_BOX);
    moneyButton2->callback(money2Click, this);


    Fl_PNG_Image* health_icon = new Fl_PNG_Image("assets/gfx/ui/Health_Icon.png");
    Fl_Image* healthIcon = health_icon->copy(50, 50);
    delete health_icon;
    healthButton1 = new Fl_Button(5, 208, healthIcon->w(), healthIcon->h());
    healthButton1->image(healthIcon);
    healthButton1->box(FL_NO_BOX);
    healthButton1->callback(health1Click, this);
    healthButton2 = new Fl_Button(1150, 208, healthIcon->w(), healthIcon->h());
    healthButton2->image(healthIcon);
    healthButton2->box(FL_NO_BOX);
    healthButton2->callback(health2Click, this);


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


    Fl_PNG_Image* move_icon = new Fl_PNG_Image("assets/gfx/ui/Move_Icon.png");
    Fl_Image* moveIcon = move_icon->copy(50, 50);
    delete move_icon;
    moveButton1 = new Fl_Button(5, 477, moveIcon->w(), moveIcon->h());
    moveButton1->image(moveIcon);
    moveButton1->box(FL_NO_BOX);
    moveButton1->callback(move1Click, this);
    moveButton2 = new Fl_Button(1150, 477, moveIcon->w(), moveIcon->h());
    moveButton2->image(moveIcon);
    moveButton2->box(FL_NO_BOX);
    moveButton2->callback(move2Click, this);


    //vessels buy buttons
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



    //giving form to terrain grid of buttons and a parallel grid of terrains that contains game data
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {

        int posX = axisX + col * (buttonSize + deadSpace);
        int posY = axisY + row * (buttonSize + deadSpace);

        terrainNodes[row][col] = new Terrain(row, col);

        terrainGrid[row][col] = new Fl_Button(posX, posY, buttonSize, buttonSize);

        TerrainPosition* location = new TerrainPosition{row, col};

        terrainGrid[row][col]->callback(terrainClick, location);
        terrainGrid[row][col]->box(FL_NO_BOX);
        }
    }

    //player playering label
    playerLog = new Fl_Box(1, 10, 0, 0, "PLAYER 1 MAKING A MOVE...");
    playerLog->labelcolor(fl_rgb_color(163, 202, 179));
    playerLog->align(FL_ALIGN_RIGHT);
    playerLog->labelsize(14);


    //multipurpose label
    announcer = new Fl_Box(1, 40, 0, 0, "HAUL: 100%");
    announcer->labelcolor(fl_rgb_color(163, 202, 179));
    announcer->align(FL_ALIGN_RIGHT);
    announcer->labelsize(14);
    announcer->hide();


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

bool Board::getSurrender(){
    return surrender;
}

bool Board::getDefeat(){
    return defeat;
}

void Board:: inspectMode() {
    inspect = true;
}

void Board:: abortInspection() {
    inspect = false;
}

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
void Board::movingMode(){
    moving = true;
}
void Board::abortMoving(){
    moving = false;
}

void Board::deactivateModes(){
    abortDocking();
    abortAttaking();
    abortSpying();
    abortUpgrading();
    abortDecoying();
    //abortMoving();
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
void Board::setMovingTerrain (Terrain* mT){
    movingTerrain = mT;
}
Terrain* Board::getMovingTerrain(){
    return movingTerrain;
}


int Board::whoWon(int round){
    //searches for win condition and returns loser player
    int points1 = 0;
    int points2 = 0;

    int loser = 0;

    if(round > 2){
        for(int i = 0; i < 8; ++i){
            for(int j = 0; j < 6; ++j){
                if(this->terrainNodes[i][j]->getVessel() != nullptr){
                    points1 += 1;
                }
            }
        }

        for(int i = 0; i < 8; ++i){
            for(int j = 6; j < 12; ++j){
                if(this->terrainNodes[i][j]->getVessel() != nullptr){
                    points2 += 1;
                }
            }
        }

        if(points1 > points2){
            loser = 1;
        } else if(points1 < points2){
            loser = 2;
        } else if(points1 == points2){
            loser = 0;
        }

    } else {
        loser = getPlayer();
    }
    
    return loser;
}

//veryfies if there is a winner when called
bool Board::verifyWinner(){
    int empty1 = 0;
    int empty2 = 0;

    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 6; ++j){
            if(this->terrainNodes[i][j]->getVessel() == nullptr){
                empty1 += 1;
            }
        }
    }

    for(int i = 0; i < 8; ++i){
        for(int j = 6; j < 12; ++j){
            if(this->terrainNodes[i][j]->getVessel() == nullptr){
                empty2 += 1;
            }
        }
    }

    if(empty1 == 48 || empty2 == 48){
        return true;
    } else {
        return false;
    }
}

//hides UI for the player not in turn and shows the UI for the player on turn
void Board::hudHide(int player) {
    
    if(player == 1){

        this->playerLog->copy_label("PLAYER 1 MAKING A MOVE...");
        this->window->redraw();

        this->moneyButton1->show();
        this->moneyButton2->hide();

        this->healthButton1->show();
        this->healthButton2->hide();

        this->moveButton1->show();
        this->moveButton2->hide();
   
        this->decoyButton1->show();
        this->decoyButton2->hide();

        this->upgradeButton1->show();
        this->upgradeButton2->hide();

        this->spiesButton1->show();
        this->spiesButton2->hide();

        this->buyVenture1->show();
        this->buyTyphon1->show();
        this->buyDugong1->show();
        this->buyCamel1->show();
        this->buyRemora1->show();
        this->buyWinterhalter1->show();

        this->buyVenture2->hide();
        this->buyTyphon2->hide();
        this->buyDugong2->hide();
        this->buyCamel2->hide();
        this->buyRemora2->hide();
        this->buyWinterhalter2->hide();


    } else if(player == 2){

        this->playerLog->copy_label("PLAYER 2 MAKING A MOVE...");
        this->window->redraw();

        this->moneyButton1->hide();
        this->moneyButton2->show(); 

        this->healthButton1->hide();
        this->healthButton2->show();

        this->moveButton1->hide();
        this->moveButton2->show();
   
        this->decoyButton1->hide();
        this->decoyButton2->show();

        this->upgradeButton1->hide();
        this->upgradeButton2->show();

        this->spiesButton1->hide();
        this->spiesButton2->show();

        this->buyVenture1->hide();
        this->buyTyphon1->hide();
        this->buyDugong1->hide();
        this->buyCamel1->hide();
        this->buyRemora1->hide();
        this->buyWinterhalter1->hide();

        this->buyVenture2->show();
        this->buyTyphon2->show();
        this->buyDugong2->show();
        this->buyCamel2->show();
        this->buyRemora2->show();
        this->buyWinterhalter2->show();
    }
}


//hides and shows the board status depending on the player making a move
void Board::terrainVeil(int player) {

    int col;
    int colEnd;

    int reshowCol;
    int reshowColEnd;

    if(player == 1){
        col = 6;
        colEnd = 12;

        reshowCol = 0;
        //6 es el scopre total
        reshowColEnd = 6;

    } else if(player == 2) {
        col = 0;
        colEnd = 6;

        reshowCol = 6;
        reshowColEnd = 12;
    }

    //esto pone la imagen del boton nula
    for(int i = col; i < colEnd; ++i){
        for(int j = 0; j < 8; ++j){
            if(this->terrainGrid[j][i]->image() != nullptr){
                this->terrainGrid[j][i]->image(nullptr);
            }
        }
    }
    
    //crear un doble for que le pregunte a terrainNode que barco tiene adentro y vuelva a poner la imagen
    for(int i = reshowCol; i < reshowColEnd; ++i){
        for(int j = 0; j < 8; ++j){
            if(this->terrainGrid[j][i]->image() == nullptr && this->terrainNodes[j][i]->isOccupied()){
                if (this->terrainNodes[j][i]->getDecoy()){
                    this->terrainGrid[j][i]->image(this->vesselSprites[this->terrainNodes[j][i]->getNameDecoy()]);
                }else{
                this->terrainGrid[j][i]->image(this->vesselSprites[this->terrainNodes[j][i]->getVesselName()]);
                }
            }   
        }
    }
}

//handles any player clicking on the board for all possible game actions
void Board::terrainClick(Fl_Widget* widget, void* actioned) {
    TerrainPosition* location = static_cast<TerrainPosition*>(actioned);
    Board* board = static_cast<Board*>(widget->parent()->user_data());
    
    Terrain* terrain = board->terrainNodes[location->longitude][location->latitude];

    Fl_Button* triggeredButton = static_cast<Fl_Button*>(widget);

    Player* currentPlayer;
    if (board->getPlayer() == 1){
        currentPlayer = board->player1;
    }
    else{
        currentPlayer = board->player2;
    }

    board->window->redraw();

    board->announcer->hide();


    if(board->moving){

        if(terrain->isOccupied() && board->movingTerrain == nullptr && !terrain->getDecoy()){
            cout<< terrain->getVesselName()<<" is moving"<<endl;
            board->setMovingTerrain(terrain);
            board->currentButton = triggeredButton;
            return;
            
        }
        else if (!terrain->isOccupied() && board->movingTerrain != nullptr){
            if (board->isPositionValid(terrain)) {
                terrain->setMovingVessel(board->movingTerrain->getVessel());
                string vesselClicked = terrain->getVesselName();
                cout<< vesselClicked<<" has moved"<<endl;
                triggeredButton->image(board->vesselSprites[vesselClicked]);
                terrain->setOccupied(true);;
                board->currentButton->image(nullptr);
                board->movingTerrain->setOccupied(false);
                board->movingTerrain->vesselNuker();
                board->setMovingTerrain(nullptr);
                triggeredButton->redraw();
                currentPlayer->deductAction();
                board->abortMoving();
                return;
            } else {
                board->setMovingTerrain(nullptr);
                board->abortMoving();
            }
        }
        if(board->movingTerrain != nullptr){
            return;
        }
        board->abortMoving();
        return;

    } else if(board->inspect && terrain->isOccupied() && !terrain->getDecoy()){
        if(board->isPositionValid(terrain)){
            cout<<"checking haul integrity"<<endl;

            cout<<terrain->getVessel()->getLife()<<endl;

            board->deactivateModes();
            board->announcer->position(triggeredButton->x() - 5, triggeredButton->y() + 60);
            string vesselData = "HAUL: " + to_string(terrain->getVessel()->getLife()) + "%";
            board->announcer->copy_label(vesselData.c_str());
            board->announcer->show();
            board->abortInspection();
        }
        else {
            board->deactivateModes();
            board->abortInspection();
        }
    } else if(board->inspect && !terrain->isOccupied()) {
        board->deactivateModes();
        board->abortInspection();
    }
    //handles docking for the first time after purchase
    else if(board->docking){

        if (board->isPositionValid(terrain) && !terrain->isOccupied()) {
            string vesselClicked = board->getVesselClicked();
            cout<< vesselClicked<<" appeared"<<endl;
            triggeredButton->image(board->vesselSprites[vesselClicked]);
            triggeredButton->redraw();
            terrain->setVessel(vesselClicked);
            terrain->setOccupied(true);
            board->callPirates(terrain, 100);
            board->abortAttaking();
            board->abortDocking();
            currentPlayer->deductAction();
            currentPlayer->spendCredits(board->cost);
        } else {
            board->abortAttaking();
            board->abortDocking();     
        }
        return;

    //handles spies conditions
    } else if(board->spying){
        if (board->attackPositionValid(terrain) 
             && terrain->isOccupied()) {
            cout<< terrain->getVesselName()<<" is being invaded"<<endl;
            if (terrain->isOccupied()){
                board->callPirates(terrain, 30);
            }
            board->abortSpying();
            currentPlayer->deductAction();
            currentPlayer->spendCredits(board->cost);
        } else {
            board->abortSpying();
        }
        return;
    }
    //handles actions of upgrading ally vessels
    else if(board->upgrading && terrain->isOccupied()){
        if (board->isPositionValid(terrain) && !terrain->getDecoy()) {
            cout<< terrain->getVesselName()<<" is being upgraded"<<endl;
            board->callUpgrade(terrain);
            board->abortUpgrading();
            // TODO: Cobrar coins
            currentPlayer->deductAction();
            currentPlayer->spendCredits(board->cost);
        } else {
            board->abortUpgrading();
        }
        return;
    }

    //handles decoy logic
    else if(board->decoying && !terrain->isOccupied()){
        if (board->isPositionValid(terrain)) {
            cout<< " A decoy has apeared"<< endl;
            string decoy = board->getDecoy();
            triggeredButton->image(board->vesselSprites[decoy]);
            terrain->setNameDecoy(decoy);
            triggeredButton->redraw();
            terrain->setOccupied(true);
            terrain->setDecoy(true);
            board->abortDecoying();
            // TODO: Cobrar pension alimenticia
            currentPlayer->deductAction();
            currentPlayer->spendCredits(board->cost);
        } else {
            board->abortDecoying();
        }
        return;
    }
    //handdler for atack logic
    else if(board->attacking){
            if (terrain->isOccupied()){
                //cout<<"Aqui3"<<endl;
                //comprobacion de que existe barco
                if(!terrain->getDecoy() && terrain->shooted(board->getDamage())){
                    //cout<<" Abeele"<< endl;
                    triggeredButton->image(nullptr);  
                    triggeredButton->redraw();
                    terrain->vesselNuker();
                    terrain->setOccupied(false);        
                }
                else if (terrain->getDecoy()){
                    triggeredButton->image(nullptr);  
                    triggeredButton->redraw();
                    terrain->setDecoy(false);
                    terrain->setOccupied(false);
                }
            }
            terrain->terrainUnderFire();

            if(!terrain->getDecoy() && terrain->isUnderFire() && terrain->isOccupied()){
                triggeredButton->image(board->vesselSprites[terrain->getVesselName()]);
            }

            board->abortAttaking();
            board->setDamage(0);
            // TODO: Cobrar coins
            currentPlayer->deductAction();
            //cout<<"Aqui1"<<endl;
        
        return;
    }
    else if(terrain->isOccupied() && !terrain->getDecoy()) {
        int damage = board->callAttack(terrain);
        board->setDamage(damage);
        board->attackingMode();
        return;
    }
    // TODO: Cuando ataca un vessel, se muestra el ataque
     
    // Aquí puedes acceder a la posición con pos->row y pos->col
    // y hacer lo que necesites con esa información
    
    //COMO USAR: creas un Fl_Button* triggeredButton = static_cast<Fl_Button*>(widget);
    //luego puedes meter logica en triggered button, ejemplo abajo ~Se3as

    board->window->redraw();
}

//checks for valid postioning
int Board::isPositionValid(Terrain* terrain) {
    int row = terrain->getPosX();
    int col = terrain->getPosY();
    int positionValid = 0;
    if (this->getPlayer() == 1) {  // player 1 board side
      positionValid = (int) (0 <= row && 0 <= player1StartCol && row < rows 
        && col < player1EndCol);
    } 
    if (this->getPlayer() == 2) {  // player 2 board side
      positionValid = (int) (0 <= row &&  player2StartCol <= col
        && row < rows && col < player2EndCol);
    }
    return positionValid;
}

//checks if objective is enemy
int Board::attackPositionValid(Terrain* terrain) {
    int row = terrain->getPosX();
    int col = terrain->getPosY();
    int attackPositionValid = 0;
    if (this->getPlayer() == 1) {  // attack player 2 board side
      attackPositionValid = (int) (0 <= row && player2StartCol <= col && row < rows 
        && col < player2EndCol);
    }
    if (this->getPlayer() == 2) {  // attack player 1 board side
      attackPositionValid = (int) (0 <= row && 0 <= player1StartCol && row < rows 
        && col < player1EndCol);
    }
    return attackPositionValid;
}

//CLICK FOR ACTION BUTTONS
void Board::money1Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(widget->parent()->user_data());
    Fl_Button* triggeredButton = static_cast<Fl_Button*>(widget);

    board->deactivateModes();

    board->announcer->position(triggeredButton->x() + 13, triggeredButton->y() - 30);
    int moneyData = board->player1->getCredits();
    cout << "Money current: " << board->player1->getCredits() << endl;
    cout << "Money data: " << moneyData << endl;
    board->announcer->copy_label(to_string(moneyData).c_str());
    board->announcer->show();
    board->window->redraw();
}

void Board::money2Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(widget->parent()->user_data());
    Fl_Button* triggeredButton = static_cast<Fl_Button*>(widget);

    board->deactivateModes();

    board->announcer->position(triggeredButton->x() + 13, triggeredButton->y() - 30);
    int moneyData = board->player2->getCredits();
    board->announcer->copy_label(to_string(moneyData).c_str());
    board->announcer->show();
    board->window->redraw();
    board->window->redraw();
}

void Board::health1Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->deactivateModes();

    board->inspectMode();
}

void Board::health2Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->deactivateModes();

    board->inspectMode();

}

void Board::decoy1Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->deactivateModes();
    board->cost = 1;
    
    if(board->player1->verifyCredit(board->cost)){;
        board->decoyingMode();
    } else {
        board->abortDecoying();
    }
}

void Board::decoy2Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->deactivateModes();
    board->cost = 1;
    
    if(board->player2->verifyCredit(board->cost)){;
        board->decoyingMode();
    } else {
        board->abortDecoying();
    }
}

void Board::upgrade1Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->deactivateModes();
    board->cost = 2;
    
    if(board->player1->verifyCredit(board->cost)){;
        board->upgradingMode();
    } else {
        board->abortUpgrading();
    }
}

void Board::upgrade2Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->deactivateModes();
    board->cost = 2;
    
    if(board->player2->verifyCredit(board->cost)){;
        board->upgradingMode();
    } else {
        board->abortUpgrading();
    }
}

void Board::spies1Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->deactivateModes();
    board->cost = 2;
    
    if(board->player1->verifyCredit(board->cost)){;
        board->spyingMode();
    } else {
        board->abortSpying();
    }
}

void Board::spies2Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->deactivateModes();
    board->cost = 2;
    
    if(board->player2->verifyCredit(board->cost)){;
        board->spyingMode();
    } else {
        board->abortSpying();
    }
}

void Board::move1Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->deactivateModes();
    board->movingMode();
}

void Board::move2Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->deactivateModes();
        board->movingMode();
}






//CLICKS FOR VESSEL PURCHASES
void Board::venture1Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
  
    board->setVesselClicked("venture");
    board->deactivateModes();
    board->cost = 3;

    if(board->player1->verifyCredit(board->cost)){;
        board->dockingMode();
    } else {
        board->abortDocking();
    }

}

void Board::venture2Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);

    board->setVesselClicked("venture");
    board->deactivateModes();
    board->cost = 3;
    
    if(board->player2->verifyCredit(board->cost)){
        board->dockingMode();
    } else {
        board->abortDocking();
    }
}

void Board::typhon1Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->setVesselClicked("typhon");
    board->deactivateModes();
    board->cost = 4;

    if(board->player1->verifyCredit(board->cost)){
        board->dockingMode();
    } else {
        board->abortDocking();
    }

}

void Board::typhon2Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->setVesselClicked("typhon");
    board->deactivateModes();
    board->cost = 4;

    if(board->player2->verifyCredit(board->cost)){
        board->dockingMode();
    } else {
        board->abortDocking();
    }
}

void Board::dugong1Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->setVesselClicked("dugong");
    board->deactivateModes();
    board->cost = 5;

    if(board->player1->verifyCredit(board->cost)){
        board->dockingMode();
    } else {
        board->abortDocking();
    }
}

void Board::dugong2Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->setVesselClicked("dugong");
    board->deactivateModes();
    board->cost = 5;
    
    if(board->player2->verifyCredit(board->cost)){
        board->dockingMode();
    } else {
        board->abortDocking();
    }
}

void Board::camel1Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->setVesselClicked("camel");
    board->deactivateModes();
    board->cost = 6;
    
    if(board->player1->verifyCredit(board->cost)){
        board->dockingMode();
    } else {
        board->abortDocking();
    }
}

void Board::camel2Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->setVesselClicked("camel");
    board->deactivateModes();
    board->cost = 6;
    
    if(board->player2->verifyCredit(board->cost)){
        board->dockingMode();
    } else {
        board->abortDocking();
    }
}

void Board::remora1Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->setVesselClicked("remora");
    board->deactivateModes();
    board->cost = 7;
    
    if(board->player1->verifyCredit(board->cost)){
        board->dockingMode();
    } else {
        board->abortDocking();
    }
}

void Board::remora2Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->setVesselClicked("remora");
    board->deactivateModes();
    board->cost = 7;
    
    if(board->player2->verifyCredit(board->cost)){
        board->dockingMode();
    } else {
        board->abortDocking();
    }
}

void Board::winterhalter1Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->setVesselClicked("winterhalter");
    board->deactivateModes();
    board->cost = 8;
    
    if(board->player1->verifyCredit(board->cost)){
        board->dockingMode();
    } else {
        board->abortDocking();
    }
}

void Board::winterhalter2Click(Fl_Widget* widget, void* actioned) {
    Board* board = static_cast<Board*>(actioned);
    board->setVesselClicked("winterhalter");
    board->deactivateModes();
    board->cost = 8;
    
    if(board->player2->verifyCredit(board->cost)){
        board->dockingMode();
    } else {
        board->abortDocking();
    }
}



//ADDS NUMBERS FOR ENEMY VESSELS BEING DEBUFFED
void Board::callPirates(Terrain* terrain, int pirates){
    unordered_set<int> initial_elements;
    int iterations = 0;
    int rango;
    if(pirates == 100){
        rango = 1;
    }
    else{
        rango = 100;
    }
    for(int i = rango; i < pirates+rango; i++){ 
        initial_elements.insert(i);                                         
    }
    for(int i = rango; i < pirates+rango; i++){
        int num = rand() % pirates + rango;
        while (initial_elements.find(num) == initial_elements.end()) {
            num = rand() % pirates + rango; 
        }
        terrain->sendPirates(num,iterations);

        double time = (terrain->getElapsed().count() * 1000000.0);
        log->register_insert(iterations,terrain->getVesselName(),time);
        iterations = 0;
    }
}


//TRIGGER FOR ATACKS
int Board::callAttack(Terrain* terrain){
    int iterations = 0;
    terrain->callAttack(iterations, damage);
    double damage = 100/(double)iterations;
    double time = (terrain->getElapsed().count() * 1000000.0);
    log->register_search(iterations, terrain->getVesselName(), damage, time);
        
    iterations = 0;
    return (int) damage;
}

//TRIGGER FOR UPGRADES
void Board::callUpgrade(Terrain* terrain){
    int upPoints = 100; // Arreglar con upPoints de player
    int iterations = 0;
    if(terrain->callUpgrade(iterations,upPoints)){
        log->register_remove(iterations, terrain->getVesselName(),
           terrain->getElapsed().count());
        iterations=0;
        for(int i=0; i < 29; i++){
            terrain->callUpgrade(iterations,upPoints);
            double time = (terrain->getElapsed().count() * 1000000.0);
            log->register_remove(iterations, terrain->getVesselName(), time);
            iterations = 0;
        }
    }
    iterations=0;
}

//MAKES IT SO A DECOY IS ALLWAYS GENERATED AS A RANDOM VESSEL
string Board::getDecoy(){
    int num = rand() % 6 + 1;
    switch(num){
    case 1:
        return "venture";
    case 2:
        return "typhon";
    case 3: 
        return "dugong";
    case 4: 
        return "camel";
    case 5:
        return "remora";
    case 6:
        return "winterhalter";
    default:
    return "";
    }
}

//LOADS ALL VESSELS SPRITES EVER NEEDED AND 2 MORE FOR FUTURE PATCHES
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

//TRIGGER FOR A PLAYER TO SURRENDER
void Board::clickSurrender(Fl_Widget*, void* actioned){
    Board* board = static_cast<Board*>(actioned);
    board->surrender = true;
}

//RETURNS THE STATUS TO KNOW IF GAME IS STILL ONGOING
bool Board::warMode() const{
    
    if(surrender){
        return surrender;
    } else if(defeat){
        return defeat;
    } else {
        return false;
    }
}

void Board::endWarMode(){
    defeat = true;
}

//SHOWS BOARD WINDOW
void Board::show(){ 
    window->show(); 
}

void Board::hide(){
    window->hide();
}

//CHANGES CURRENT PLAYER
void Board::swapPlayer(){
    if(player == 1){
      player = 2;
    } else {
      player = 1;
    }
  }

int Board::getPlayer(){
    return player;
}

Board::~Board(){
    if(window) {
        window->hide();  
        delete window; 
        delete log;
    }
}