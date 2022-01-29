#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "recursion.h"

//
// Calls the functions from recursion.h.
// You should NOT edit this file.
//

std::map<std::string, bool> LoadWords() {
  std::map<std::string, bool> words;
  std::ifstream file;
  file.open("scrabble_words.txt");
  std::string word;
  // First two lines copyright related.
  std::getline(file, word);
  std::cout << word << std::endl;
  std::getline(file, word);
  std::cout << word << std::endl;
  while (std::getline(file, word) && word.size() > 0) {
    words[word] = true;
  }
  file.close();
  return words;
}

int main() {
  std::map<std::string, bool> words = LoadWords();
  std::string choice;
  std::cout << "Note that the dictionary uses only capital letters.\n"
            << std::endl;
  while (choice != "quit") {
    std::cout << "Which problem do you want to test? "
              << "(1: Unscramble, 2: ScrabbleSolver, 3: ScrabbleNoDupes, or "
                 "\"quit\"): ";
    std::cin >> choice;
    if (choice == "1") {
      std::string value;
      std::cout << "What letters do you want to unscramble? ";
      std::cin >> value;
      std::cout << "Calculating possible unscrambles..." << std::endl;
      Unscramble(value, words);
      std::cout << "Unscrable completed." << std::endl;
    } else if (choice == "2") {
      std::string value;
      std::cout << "What scrabble tiles do you have? ";
      std::cin >> value;
      std::cout << "Calculating all scrabble words..." << std::endl;
      ScrabbleSolver(value, words);
      std::cout << "Scrabble solver completed." << std::endl;
    } else if (choice == "3") {
      std::string value;
      std::cout << "What scrabble tiles do you have? ";
      std::cin >> value;
      std::cout << "Calculating all scrabble words without duplications..."
                << std::endl;
      ScrabbleSolverNoDupes(value, words);
      std::cout << "Scrabble solver completed." << std::endl;
    }
  }
  return 0;
}
