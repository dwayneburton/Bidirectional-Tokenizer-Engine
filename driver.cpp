// Including the necessary header files
#include <iostream>
#include <string>
#include "tokenize.h"
#include <sstream>

int main(){
    // Variable initializations and declarations
    std::string input;
    std::string command;
    int parameter;
    std::string word;
    TwoWayHashMap Dictionary;

    // Loop that runs until the user enters the "exit" command
    while (std::getline(std::cin, input)) {
        
        std::istringstream iss(input);
        iss >> command;

        // Creates a HashMap array of a given user-inputted size given the "create" command
        if (command == "create") {
            iss >> parameter;
            Dictionary.create(parameter);
            std::cout << "success" << std::endl;

        // Inserts a Word-Token pair into the Bidirectional HashMap given the "insert" command
        } else if (command == "insert") {
            iss >> word;
            if (Dictionary.insert(word)) {
                std::cout << "success" << std::endl;
            } else {
                std::cout << "failure" << std::endl;
            }
        
        // Inserts all words from a file into the Bidirectional HashMap given the "load" command
        } else if (command == "load") {
            iss >> word;
            if (Dictionary.load(word)) {
                std::cout << "success" << std::endl;
            } else {
                std::cout << "failure" << std::endl;
            }
        
        // Prints the token using the word (key) given the "tok" command
        } else if (command == "tok") {
            iss >> word;
            std::cout << Dictionary.tok(word) << std::endl;
        
        // Prints the word using the token (key) given the "ret" command
        } else if (command == "ret") {
            iss >> parameter;
            std::cout << Dictionary.ret(parameter) << std::endl;
        
        // Prints all the tokens using the words (keys) given the "tok_all" command
        } else if (command == "tok_all") {
            while (iss >> word) {
                std::cout << Dictionary.tok(word) << " ";
            }
            std::cout << std::endl;
        
        // Prints all the words using the tokens (keys) given the "ret_all" command
        } else if (command == "ret_all") {
            while (iss >> parameter) {
                std::cout << Dictionary.ret(parameter) << " ";
            }
            std::cout << std::endl;
        
        // Prints all the words in the HashMap array at a user-inputted index given the "print" command
        } else if (command == "print") {
            iss >> parameter;
            Dictionary.print(parameter);

        // Ends the program given the "exit" command
        } else if (command == "exit") {
            break;
        }
    }
}