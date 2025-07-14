#include <iostream>
#include <windows.h>

#include "include/WordLoad.h"
#include "include/Word.h"
#include "include/Game.h"
#include "include/Menu.h"
#include "include/Art.h"

int main (){

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Menu menu;
    std::string langCode = menu.selectLanguageCode();

    WordLoad loader;
    loader.loadWords(langCode);

    std::string word = loader.getRandomWord();

    if (word.empty()) {
        std::cerr << "[!] No word loaded. Exiting.\n";
        return 1;
    }

    Game game(word);
    game.play();

    return 0;
}
