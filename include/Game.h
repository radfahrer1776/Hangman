#pragma once

#include <iostream>
#include <string>
#include <cctype>
#include <thread>
#include <chrono>

#include "Art.h"
#include "Word.h"


class Game {
    private:
        Word word;
        int maxAttempts;
        int attemptsLeft;
         std::set<char> incorrectLetters;

    public:
        Game(const std::string& targetWord, int maxAttempts = 6);
        void displayHangman() const;
        void play();
    
    private:
        void displayState() const;
        char getUserInput() const;
        void printEndMessage ()const;

};
