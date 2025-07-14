#include "../include/WordLoad.h"
#include "../include/Utils.h"

WordLoad::WordLoad() {}

void WordLoad::loadWords(const std::string& langCode) {
    std::string filename = "data/word_" + langCode + ".txt";

    std::ifstream file(filename);
    if (!file) {
        std::cerr << "[!] Cannot open file: " << filename << "\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            words.push_back(line);
        }
    }

    if (words.empty()) {
        std::cerr << "[!] No words found in: " << filename << "\n";
    }
}

std::string WordLoad::getRandomWord() const {
    if (words.empty()) return "";

    static std::mt19937 rng(std::time(nullptr));
    std::uniform_int_distribution<size_t> dist(0, words.size() - 1);

    return words[dist(rng)];
}