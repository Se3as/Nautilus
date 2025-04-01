// #include <Fl/Fl.H>
// #include <Fl/Fl_Window.H>
// #include <Fl/Fl_Input.H>
// #include <Fl/Fl_Button.H>
// #include <Fl/Fl_Box.H>
// #include <Fl/Fl_Check_Button.H>
// #include <Fl/Fl_PNG_Image.H>
// #include <Fl/Fl_JPEG_Image.H>
// #include <SDL2/SDL.h>
// #include <SDL2/SDL_mixer.h>
// #include <iostream>

// void menu();
// void board();
// Fl_Window* menu_window = nullptr;
// Fl_Button* play = nullptr;
// Fl_Button* quit = nullptr;

// Mix_Music* bg_music = nullptr;

// //preguntar
// void init_audio() {
//     // Inicializar SDL y SDL_mixer
//     if (SDL_Init(SDL_INIT_AUDIO) < 0) {
//         std::cerr << "SDL no pudo inicializarse: " << SDL_GetError() << std::endl;
//         return;
//     }

//     if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
//         std::cerr << "SDL_mixer no pudo inicializarse: " << Mix_GetError() << std::endl;
//         return;
//     }

//     // Cargar música
//     bg_music = Mix_LoadMUS("assets/sfx/Barotrauma OST_ Embrace the Abyss (Menu Theme).mp3");
//     if (!bg_music) {
//         std::cerr << "No se pudo cargar la música: " << Mix_GetError() << std::endl;
//         return;
//     }

//     // Reproducir en bucle
//     Mix_PlayMusic(bg_music, -1);
// }

// //preguntar
// void close_audio() {
//     if (bg_music) {
//         Mix_HaltMusic();
//         Mix_FreeMusic(bg_music);
//         bg_music = nullptr;
//     }
//     Mix_CloseAudio();
//     SDL_Quit();
// }




// void game_start(Fl_Widget*, void*) {
//     //close_audio();
//     delete menu_window;
//     menu_window = nullptr;
    
//     board();
// }


// void game_quit(Fl_Widget*, void*) {
//     close_audio();
//     delete menu_window;
//     menu_window = nullptr;
// }

// void menu() {


//     Fl_JPEG_Image* nauti_menu3 = new Fl_JPEG_Image("assets/gfx/backgrounds/nauti_menu3.jpg");
//     Fl_Image* menuQHD = nauti_menu3->copy(960, 540);

//     menu_window = new Fl_Window(menuQHD->w(), menuQHD->h(), "Welcome!");

//     delete nauti_menu3;

//     Fl_Box* mainMenu = new Fl_Box(0, 0, menuQHD->w(), menuQHD->h());
//     mainMenu->image(menuQHD);

    
//     Fl_JPEG_Image* play_button1 = new Fl_JPEG_Image("assets/gfx/ui/play_button.jpg");
//     Fl_Image* play_button = play_button1->copy(150, 40);
    
//     delete play_button1;

//     play = new Fl_Button(400, 400, play_button->w(), play_button->h());
//     play->image(play_button);

//     play->callback(game_start);

//     Fl_JPEG_Image* quit_button1 = new Fl_JPEG_Image("assets/gfx/ui/quit_button.jpg");
//     Fl_Image* quit_button = quit_button1->copy(150, 40);
    
//     delete quit_button1;

//     quit = new Fl_Button(400, 450, quit_button->w(), quit_button->h());
//     quit->image(quit_button);

//     quit->callback(game_quit);

//     menu_window->end();
//     menu_window->show();
// }


// void board() {
    
//     int uiSizeW = 1280;
//     int uiSizeH = 720;

//     //esto crea la ventanita donde ocurre la magia
//     Fl_Window* board_window = new Fl_Window(uiSizeW, uiSizeH, "Nautilus");

//     //imagen del mapa
//     Fl_JPEG_Image* nauti_map1 = new Fl_JPEG_Image("assets/gfx/backgrounds/nauti_map1.jpg");
//     Fl_Image* background = nauti_map1->copy(uiSizeW, uiSizeH);
//     delete nauti_map1;
//     Fl_Box* uiBox = new Fl_Box(0, 0, background->w(), background->h());
//     uiBox->image(background);



//     //submarino de prueba
//     Fl_PNG_Image* selkie_px800 = new Fl_PNG_Image("assets/gfx/vessels/800px-Selkie.png");
//     Fl_Image* selkie = selkie_px800->copy(62, 30);
//     delete selkie_px800;
//     Fl_Box* selkie_box = new Fl_Box(197, 220, selkie->w(), selkie->h());
//     selkie_box->image(selkie);


//     board_window->end();
//     board_window->show();
// };


// int main() {
//     init_audio();
//     menu();
    
//     return Fl::run();
//     close_audio();
// }