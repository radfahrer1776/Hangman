#pragma once

#include "Word.h"

#include <iostream>
#include <string>
#include <cctype>

class Game {
    private:
        Word word;
        int maxAttempts;
        int attemptsLeft;

    public:
        Game(const std::string& targetWord, int maxAttempts = 6);
        void displayHangman() const;
        void play();
    
    private:
        void displayState() const;
        char getUserInput() const;
        void printEndMessage ()const;

};
