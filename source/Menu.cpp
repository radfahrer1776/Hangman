#include "../include/Menu.h"

void Menu::display() const {
    std::string menu =
        "╔═════════════════════╗\n"
        "║    H A N G M A N    ║\n"
        "╠═════════════════════╣\n"
        "║ 1. English          ║\n"
        "║ 2. Ukrainian        ║\n"
        "║ 3. Russian          ║\n"
        "║                     ║\n"
        "║ 0. Exit             ║\n"
        "╚═════════════════════╝\n";
    
    std::cout << menu;
}