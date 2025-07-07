#include "../include/Game.h"

Game::Game (const std::string& targetWord, int maxAttempts)
    : word(targetWord), maxAttempts(maxAttempts), attemptsLeft(maxAttempts) {}

void Game::play() {
    while (attemptsLeft > 0 && !word.isFullyGuessed()){
        
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        displayHangman();
        displayState();

        char guess = getUserInput();

        if (word.guessLetter(guess)) {
            std::cout << "Good! The letter '" << guess << "' is in the word.\n";
        } else {
            attemptsLeft--;
            std::cout << "Oops! The letter '" << guess << "' is NOT in the word.\n";
        }
    }
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
    
    displayHangman();
    printEndMessage();
}

char Game::getUserInput() const {
    std::string input;
    
    while(true) {
        std::cout << "Enter a letter: ";
        std::getline(std::cin, input);
        
        if (input.length() == 1 && std::isalpha(input[0])){
            char letter = std::tolower(input[0]);
            return letter;
        } else {
            std::cout << "[Error] | Enter one letter \n";
        }
    }
}

void Game::displayState() const {
    std::cout << "Word: " << word.getMaskedWord() << "\n";
    std::cout << "Attempts left: " << attemptsLeft << '|' << maxAttempts << "\n";
    
}

void Game::printEndMessage() const {
    if (word.isFullyGuessed()) {
        std::cout << "Congrats! You guessed the word: " << word.getMaskedWord() << "\n";
    } else {
        std::cout << "Game over! The word was: " << word.getOriginalWord() << "\n";
    }
}

void Game::displayHangman() const{

    int errors = maxAttempts - attemptsLeft;

    std::cout << "\n";
    std::cout << "╔═════════════════╗\n";
    std::cout << "║     Hangman     ║\n";
    std::cout << "╠════════╦════════╣\n";
    std::cout << "║        ║        ║\n";

    switch (errors) {
        case 0:
            std::cout << "║                 ║\n";
            std::cout << "║                 ║\n";
            std::cout << "║                 ║\n";
            std::cout << "║                 ║\n";
            break;
        case 1:
            std::cout << "║        O        ║\n";
            std::cout << "║                 ║\n";
            std::cout << "║                 ║\n";
            std::cout << "║                 ║\n";
            break;
        case 2:
            std::cout << "║        O        ║\n";
            std::cout << "║        |        ║\n";
            std::cout << "║                 ║\n";
            std::cout << "║                 ║\n";
            break;
        case 3:
            std::cout << "║        O        ║\n";
            std::cout << "║       /|        ║\n";
            std::cout << "║                 ║\n";
            std::cout << "║                 ║\n";
            break;
        case 4:
            std::cout << "║        O        ║\n";
            std::cout << "║       /|\\       ║\n";
            std::cout << "║                 ║\n";
            std::cout << "║                 ║\n";
            break;
        case 5:
            std::cout << "║        O        ║\n";
            std::cout << "║       /|\\       ║\n";
            std::cout << "║       /         ║\n";
            std::cout << "║                 ║\n";
            break;
        case 6:
            std::cout << "║        X        ║\n";
            std::cout << "║       /|\\       ║\n";
            std::cout << "║       / \\       ║\n";
            std::cout << "║                 ║\n";
            break;
        default:
            std::cout << "║                 ║\n";
            std::cout << "║ [Unknown state] ║\n";
            std::cout << "║                 ║\n";
            std::cout << "║                 ║\n";
            break;
    }

    std::cout << "╚═════════════════╝\n";
}