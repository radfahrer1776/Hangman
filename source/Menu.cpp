#include "../include/Menu.h"
#include "../include/Utils.h"

std::string Menu::selectLanguageCode() const {

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
    
    int choice = -1;
    while (true) {
        std::cout << menu;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::this_thread::sleep_for(std::chrono::microseconds(1500));
            clearConsole();
            std::cout << "[!] Invalid input. Please enter a number.\n";
            continue;
        }

        std::cin.ignore(32767, '\n');

        if (choice == 0) {
            exit(0);
        } else if (choice == 1) {
            return "en";
        } else if (choice == 2) {
            return "ua";
        } else if (choice == 3) {
            return "ru";
        } else {
            std::this_thread::sleep_for(std::chrono::microseconds(1500));
            clearConsole();
            std::cout << "[!] Invalid choice. Try again.\n";
        }
    }
}