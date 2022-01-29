// Name: Joseph Eggers
// CWID: 885939488
// Email: joseph.eggers@scu.fullerton.edu

#include "recursion.h"

#include <iostream>
#include <string>
#include <vector>

using std::cout, std::endl, std::map, std::string, std::vector;

// In recursion it's normal to have a helper function call the recursive
// function, passing in the appropriate parameters to start the recursion.
// In this case, the Unscramble function should create a helper function which
// is recursive.
void UnscrambleHelper(vector<string>& permutation, string Head, string tail) {
  // base Case is 1
  if (tail.size() == 0) {
    // If the Tail is 0 bush Back Head
    permutation.push_back(Head);
  }
  // recursive Case
  for (size_t j = 0; j < tail.size(); j++) {
    string tempHead = Head;
    string tempTail = tail;
    tempHead.push_back(tail[j]);
    tempTail.erase(j, 1);
    // Call Function Again
    UnscrambleHelper(permutation, tempHead, tempTail);
  }
}

void ScrabberSolverHelper(vector<string>& permutation, string Head,
                          string tail) {
  // base Case is 1
  if (tail.size() == 0) {
    // Do nothing since tail = 0 was already pushed
  }
  // recursive Case
  for (size_t j = 0; j < tail.size(); j++) {
    string tempHead = Head;
    string tempTail = tail;
    tempHead.push_back(tail[j]);
    tempTail.erase(j, 1);
    // Push head of word2
    permutation.push_back(tempHead);
    // Call Function Again
    ScrabberSolverHelper(permutation, tempHead, tempTail);
  }
}

void ScrabbleSolverNoDupesHelper(vector<string>& permutation,
                                 map<std::string, bool>& used_words,
                                 string Head, string tail) {
  // base Case is 0
  if (tail.size() == 0) {
    // Do nothing since tail = 0 was already pushed
  }
  // recursive Case
  for (size_t j = 0; j < tail.size(); j++) {
    string tempHead = Head;
    string tempTail = tail;
    tempHead.push_back(tail[j]);
    tempTail.erase(j, 1);
    // Push head of word
    permutation.push_back(tempHead);
    used_words.insert(std::pair<string, bool>(tempHead, false));
    // Call Function Again
    ScrabbleSolverNoDupesHelper(permutation, used_words, tempHead, tempTail);
  }
}

void Unscramble(string letters, std::map<std::string, bool>& words) {
  // TODO
  // Vector Permutation
  vector<string> permutation;
  UnscrambleHelper(permutation, "", letters);
  for (size_t k = 0; k < permutation.size(); k++) {
    if (words[permutation[k]]) {
      cout << "The word " << permutation[k] << " is in the dictionary!\n";
    }
  }
}

// Like Unscramble, ScrabbleSolver should create a helper function which is
// is recursive.
void ScrabbleSolver(std::string letters, std::map<std::string, bool>& words) {
  // TODO
  vector<string> permutation;
  // Recursive Function
  ScrabberSolverHelper(permutation, "", letters);
  for (size_t k = 0; k < permutation.size(); k++) {
    if (words[permutation[k]]) {
      cout << "The word " << permutation[k] << " is in the dictionary!\n";
    }
  }
}

// ScrabbleSolverNoDupes needs to keep track of the previous words which were
// found in order not to print them again. Create a recursive helper function to
// recursively unscramble without duplications.
void ScrabbleSolverNoDupes(std::string letters,
                           std::map<std::string, bool>& words) {
  // TODO
  vector<string> permutation;
  map<std::string, bool> used_words;
  // Recursive Function
  ScrabbleSolverNoDupesHelper(permutation, used_words, "", letters);
  for (size_t k = 0; k < permutation.size(); k++) {
    if (words[permutation[k]] && (used_words[permutation[k]] == false)) {
      used_words[permutation[k]] = true;
      cout << "The word " << permutation[k] << " is in the dictionary!\n";
    }
  }
}
