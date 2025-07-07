#include <iostream>

#include "include/Word.h"

int main (){

   SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::string targetWord = "Hello, world!";

    Game game(targetWord);
    game.play();

    return 0;
}
