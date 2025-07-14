#include "../include/Word.h"

Word::Word(const std::string& original) : originalWord(original){
    for (size_t i = 0; i < originalWord.size(); ++i) {
        if (std::isspace(originalWord[i]) || std::ispunct(originalWord[i]))
            currentMask += originalWord[i];
        else
            currentMask += '_';
        }
}

std::string Word::getMaskedWord() const {
    return currentMask;
}

const std::string& Word::getOriginalWord() const {
    return originalWord;
}

bool Word::guessLetter(char letter) {
    letter = std::tolower(letter);
    if (wasGuessedBefore(letter)) {
        return false;
    }

    bool found = false;
    for (size_t i = 0; i < originalWord.size(); ++i) {
        if (std::tolower(originalWord[i]) == letter) {
            currentMask[i] = originalWord[i];
            found = true;
        }
    }
    if (found) {
        guessedLetters.insert(letter);
    }
    return found;
}

bool Word::isFullyGuessed() const {
    return currentMask == originalWord;
}

bool Word::wasGuessedBefore(char letter) const {
    letter = std::tolower(letter);
    return guessedLetters.count(letter) > 0;
}

