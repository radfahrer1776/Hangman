#include "../include/Game.h"
#include "../include/Utils.h"

Game::Game(const std::string& targetWord, int maxAttempts)
    : word(targetWord), maxAttempts(maxAttempts), attemptsLeft(maxAttempts) {}

void Game::play() {
    while (attemptsLeft > 0 && !word.isFullyGuessed()) {
        clearConsole();
        displayHangman();
        displayState();

        std::cout << "Enter a letter: ";
        char guess = getUserInput();

        if (guess == 0) {
            std::cout << "[!] Enter a single letter.\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1500));
            continue;
        }

        if (word.wasGuessedBefore(guess) || incorrectLetters.count(guess) > 0) {
            std::cout << "[!] You already guessed the letter '" << guess << "'. Try another one.\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1500));
            continue;
        }

        if (word.guessLetter(guess)) {
            std::cout << "Good! The letter '" << guess << "' is in the word.\n";
        } else {
            incorrectLetters.insert(guess);
            attemptsLeft--;
            std::cout << "Oops! The letter '" << guess << "' is NOT in the word.\n";
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    }

    clearConsole();
    displayHangman();
    printEndMessage();
}

char Game::getUserInput() const {
    std::string input;
    std::getline(std::cin, input);

    input.erase(0, input.find_first_not_of(" \t\n\r\f\v"));
    input.erase(input.find_last_not_of(" \t\n\r\f\v") + 1);

    if (input.length() == 1 && std::isalpha(input[0])) {
        return std::tolower(input[0]);
    } else {
        return 0;
    }
}

void Game::displayState() const {
    std::cout << "Word: " << word.getMaskedWord() << "\n";
    std::cout << "Attempts left: " << attemptsLeft << " | " << maxAttempts << "\n";

    std::cout << "Incorrect letters: ";
    if (incorrectLetters.empty()) {
        std::cout << "(none)";
    } else {
        for (char c : incorrectLetters) std::cout << c << ' ';
    }
    std::cout << "\n";
}

void Game::printEndMessage() const {
    const int errors = maxAttempts - attemptsLeft;

    clearConsole();

    if (word.isFullyGuessed()) {
        HangmanArt::displayWin(errors);
        std::cout << "Congrats! You guessed the word: " << word.getOriginalWord() << "\n";
    } else {
        HangmanArt::display(errors);
        std::cout << "Game over! The word was: " << word.getOriginalWord() << "\n";
    }
}

void Game::displayHangman() const {
    const int errors = maxAttempts - attemptsLeft;
    HangmanArt::display(errors);
}