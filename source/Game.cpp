#include "../include/Game.h"

#include <string>
#include <set>

Word::Word(const std::string& original) : originalWord(original){
    currentMask = std::string(original.size(), '_');
}

std::string Word::getMaskedWord() const {
    return currentMask;
}

bool Word::guessLetter(char letter){
    bool found = false;

    for (int i = 0; i < originalWord.size(); ++i){
        if (originalWord[i] == letter){
            currentMask[i] = letter;
            found = true;
        }
    }

    guessedLetters.insert(letter);

    return found;
}