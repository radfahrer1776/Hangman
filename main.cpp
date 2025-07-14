#include <iostream>
#include <windows.h>

#include "include/Word.h"
#include "include/Game.h"
#include "include/Menu.h"

int main (){

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::string targetWord = "zxcv";

    Menu menu;
    menu.display();


    Game game(targetWord);
    game.play();

    return 0;
}
