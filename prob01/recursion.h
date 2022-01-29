#include <map>
#include <string>

// Prints out all words in the |words| map that can be created by permutations
// of the letters in the |letters| string.
void Unscramble(std::string letters, std::map<std::string, bool>& words);

// Prints out all words in the |words| map that can be created if you have the
// scrabble tiles in the |letters| string.
void ScrabbleSolver(std::string letters, std::map<std::string, bool>& words);

// Prints out all words in the |words| map that can be created if you have the
// scrabble tiles in the |letters| string, but does not print out duplicates.
void ScrabbleSolverNoDupes(std::string letters,
                           std::map<std::string, bool>& words);
