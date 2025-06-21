// Including the necessary header files
#include "tokenize.h"
#include <string>
#include <list>
#include <utility>
#include <fstream>
#include <iostream>
#include <cctype>

// Destructor that deletes the HashMap array
HashMap::~HashMap() {
    delete[] array;
}

// Given hash function
unsigned HashMap::hash(const std::string & str) {
    unsigned ans = 0;
    for (auto it = str.begin(); it != str.end(); ++it) {
        ans = ans * 29 + *it;
    }
    return ans % size;
}

// Creates the hash map array given a user-inputted size
void HashMap::create(int size) {
    this->size = size;
    array = new std::list<std::pair<std::string, int>> [size];
}

// Inserts a Word-Token pair into the Hashmap array
bool HashMap::insert(std::string &word, int token) {
    unsigned int index = hash(word);
    for (char &c: word) {
        if (!std::isalpha(c)) {
            return false;
        }
    }

    for (auto &pair: array[index]){
        if (pair.first == word) {
            return false;
        }
    }
    inserts++;
    array[index].push_back({word, token});
    if (double(inserts)/size >= 0.8) {
        rehash();
    }
    return true;
}

// Updates HashMap array size and rehashes all keys
void HashMap::rehash() {
    int old_size = size;
    size *= 2;
    std::list<std::pair<std::string, int>> *temp = new std::list<std::pair<std::string, int>> [size];
    for (int i = 0; i < old_size; i++) {
        for (auto &pair: array[i]) {
            temp[hash(pair.first)].push_back({pair.first, pair.second});
        }
    }
    delete[] array;
    array = temp;
}

// Retrieves the token of a word
int HashMap::tok(std::string &word) {
    unsigned int index = hash(word);
    for (auto &pair: array[index]){
        if (pair.first == word) {
            return pair.second;
        }
    }
    return -1;
}

// Prints all words at a given token
void HashMap::print(int hash_value) {
    if ((hash_value >= 0 && hash_value < size) && !array[hash_value].empty()) {
        for (auto &pair: array[hash_value]) {
            std::cout << pair.first << " ";
        }
        std::cout << std::endl;
    }
}

// Create helper function that calls create function of HashMap class
void TwoWayHashMap::create(int size) {
    Map.create(size);
    Vector.push_back("");
}

// Inserts a Key-Value pair into both the HashMap and Vector
bool TwoWayHashMap::insert(std::string &word) {
    if (Map.insert(word, Vector.size())) {
        Vector.push_back(word);
        return true;
    }
    return false;
}

// Inserts all words from a file into the HashMap and Vector
bool TwoWayHashMap::load(std::string &filename) {
    std::ifstream file(filename);
    std::string word;
    bool inserted = false;
    while (file >> word) {
        if (insert(word)) {
            inserted = true;
        }
    }
    file.close();
    return inserted;
}

// Tok helper function that calls tok function of the Hashmap class
int TwoWayHashMap::tok(std::string &word) {
    return Map.tok(word);
}

// Retrieves Word given a token
std::string TwoWayHashMap::ret(unsigned int token) {
    if (token < Vector.size() && token > 0) {
        return Vector[token];
    }
    return "N/A";
}

// Print helper function that calls the print function of the HashMap class
void TwoWayHashMap::print(int hash_value) {
    Map.print(hash_value);
}