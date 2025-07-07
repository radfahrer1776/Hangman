#include <iostream>

#include "include/Word.h"

int main (){

    Word word ("Hello, world!");
    std::cout << word.getMaskedWord() << "\n";

    word.guessLetter('o');
    std::cout << word.getMaskedWord() << "\n";

    word.guessLetter('o');
    std::cout << word.getMaskedWord() << "\n";

    word.guessLetter('l');
    std::cout << word.getMaskedWord() << "\n";

    word.guessLetter('h');
    std::cout << word.getMaskedWord() << "\n";

    word.guessLetter('d');
    std::cout << word.getMaskedWord() << "\n";

    word.guessLetter('!');
    std::cout << word.getMaskedWord() << "\n";

    word.guessLetter('W');
    std::cout << word.getMaskedWord() << "\n";

    word.guessLetter(',');
    std::cout << word.getMaskedWord() << "\n";

    word.guessLetter('e');
    std::cout << word.getMaskedWord() << "\n";

    return 0;
}