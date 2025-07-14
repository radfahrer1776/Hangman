#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>
#include <ctime>

class WordLoad {
public:
    WordLoad();
    void loadWords(const std::string& langCode);
    std::string getRandomWord() const;

private:
    std::vector<std::string> words;
};