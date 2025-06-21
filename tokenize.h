// Including the necessary header files
#include <vector>
#include <string>
#include <list>
#include <utility>

// HashMap class definition
class HashMap {
    // Private member variables
    private:
    std::list<std::pair<std::string, int>> *array;  // Hashmap array
    int inserts = 0;                                // Number of key & value pairs in the HashMap
    int size = 0;                                   // Size of HashMap array

    // Public member functions
    public:
    ~HashMap();                                 // Destructor that deletes the HashMap array
    unsigned hash(const std::string &word);     // Given hash function
    void create(int size);                      // Creates the hash map array given a user-inputted size
    bool insert(std::string &word, int token);  // Inserts a Word-Token pair into the Hashmap array
    void rehash();                              // Updates HashMap array size and rehashes all keys
    int tok(std::string &word);                 // Retrieves the token of a word
    void print(int hash_value);                 // Prints all words at a given token
};

// Bidirectional HashMap class definition
class TwoWayHashMap {
    // Private member variables
    private:
    std::vector<std::string> Vector;    // Token to Word Vector
    HashMap Map;                        // Word to Token HashMap

    // Public member functions
    public:
    void create(int size);                  // Create helper function that calls create function of HashMap class
    bool insert(std::string &word);         // Inserts a Key-Value pair into both the HashMap and Vector
    bool load(std::string &filename);       // Inserts all words from a file into the HashMap and Vector
    int tok(std::string &word);             // Tok helper function that calls tok function of the Hashmap class
    std::string ret(unsigned int token);    // Retrieves Word given a token
    void print(int hash_value);             // Print helper function that calls the print function of the HashMap class
};