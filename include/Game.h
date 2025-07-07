#pragma once

#include <string>
#include <set>

class Word{
    private:
        std::string originalWord;
        std::string currentMask;
        std::set<char> guessedLetters;

    public:
        Word (const std::string& original);
        bool guessLetter (char letter);
        std::string getMaskedWord () const;
        // bool isFullyGuessed () const;
        // bool wasGuessedBefore (char letter) const;
};