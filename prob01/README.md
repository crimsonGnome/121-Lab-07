# Recursive Scrabble Solver

In this lab you will work on extending the recursive ``Permute`` function from class to create a program which can unscramble letters to form words, like the board game Scrabble.

You will complete three recursive functions in ``recursion.cc``. You do not need to edit any other files.

## Run the program (yes, you can try now!)

To manually test your code you can compile and run by linking to ``main.cc`` and ``recursion.cc``:

```
clang++ -std=c++17 main.cc recursion.cc -o main
./main
```

You can pick which function to try and follow the prompts. All input should be strings with only capital letters A-Z. Please note that the dictionary provided uses only capital letters!

## Note on grading
If you do not use recursion you will not get credit.

In order to provide partial credit, this builds to the final solution in stages, by having you implement three different functions. Part 1 builds on the ``Permute`` function, Part 2 extends Part 1, and Part 3 on Part 2. You should do your best to work through all three parts in order, but note that each one has its own tests, so even if you can't complete the whole thing we still will give partial credit. (Run ``make noskiptest`` to see how many total tests you will pass).

## Part 1: Unscramble

Implement ``Unscramble``. This function takes as parameters a ``std::string`` of letters to unscramble and a dictionary of English words in a ``std::map<std::string, bool>&``. Instead of printing every word like in ``ListPermutations``, your function should only print out words which are in the dictionary.

A word is in the dictionary if the value at that key is ``true``. For example, we can check if the word "CAT" is in the map ``words`` as follows:

```cpp
if (words["CAT"]) {
  std::cout << "The word CAT is in the dictionary!\n";
}
```

Example output of the ``Unscramble`` of "TCA" would be "CAT" and "ACT", and "GDSO" would give "DOGS" and "GODS". Also try "THATS", which has a lot of solutions!

*Hint: You need to create a recursive helper function that can be called by ``Unscramble``. This function can take an additional parameter, a ``std::string`` prefix to start with. Define this function at the top of the ``recursion.cc`` file.*

*Like ``Permute``, the base case of the recursive unscramble function is when the size of the remaining string is zero. However, ``Unscramble`` must also check that the word is in the ``words`` dictionary.*

*Like ``Permute``, the recursive case should, for each letter in the remaining string, recursively unscramble using a new prefix composed of the previous prefix plus one letter of the remaining string.*

## Part 2: ScrabbleSolver

In Scrabble you have a set of tiles and you can form words with those tiles that can be of any length. ``ScrabbleSolver`` will find all the words that can be created with a set of letters, not just the permutations of those letters. That is, for the Scrabble tiles "TCA", you would get the words "CAT", "ACT", "AT" and "TA".

This is very similar to ``Unscramble``. Instead of only checking whether a word is in the ``words`` map when the ``prefix`` is empty, you can always check whether a ``prefix`` is in the words map and ``cout`` that prefix immediately.

*Hint: Make a second recursive helper function which can be called by ScrabbleSolver and takes any necessary arguments to start the recursion.*

## Part 3: ScrabbleSolverNoDupes

You may have noticed that ``ScrabbleSolver`` ends up printing duplicate words if you have duplicate letters. For example, for the letters "CLLA", ``ScrabbleSolver`` prints out some words twice, like "CAL", "CALL", "ALL". In fact, any letter with an "L" is printed twice.

In this part you should implement a scrabble solver that ensures no duplicate words are printed by keeping track of the words which are already found. You can do this by using a ``std::map<std::string, bool>&`` parameter, ``used_words`` in your recursive helper function. Each time you find a new valid word, put it in ``used_words`` so that you don't use it again.

*Note*: ``used_words`` is a reference type because we want to use exactly one version of the map no matter which recursive function we are in. If we passed ``used_words`` by value then any modifications would not persist!

*Hint: Make a third recursive helper function which can be called by ``ScrabbleSolverNoDupes`` and takes any necessary arguments to start the recursion.*


## Notes on debugging

* If you get a stack overflow error it means you never reach a base case and the recursion goes on forever.

* You can use cout and small inputs to determine what's happening

* The dictionary being used is in scrabble_words.txt, so you can see what words are available. There are no one-letter words in scrabble_words.txt.

## Run the unit tests

We've provided unit tests, which you can try with ``make test``. Use the output to help you debug any issues in your program.

# Submission checklist
1. Compiled and ran the driver (`main`).
1. Manually checked for compilation and logical errors.
1. Ensured no errors on the unit test (`make test`).
1. Followed advice from the stylechecker (`make stylecheck`).
1. Followed advice from the formatchecker to improve code readability (`make formatcheck`).

# Code evaluation
Open the terminal and navigate to the folder that contains this exercise. Assuming you have pulled the code inside of `/home/student/labex02-tuffy` and you are currently in `/home/student` you can issue the following commands

```
cd labex02-tuffy
```

You also need to navigate into the problem you want to answer. To access the files needed to answer problem 1, for example, you need to issue the following command.

```
cd prob01
```

When you want to answer another problem, you need to go back up to the parent folder and navigate into the next problem. Assuming you are currently in `prob01`, you can issue the following commands to go to the parent folder then go into another problem you want to answer; `prob02` for example.

```
cd ..
cd prob02
```

Use the `clang++` command (or ``make build``) to compile your code and the `./` command to run it. The sample code below shows how you would compile code save in `main.cc` and `recursion.cc` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cc recursion.cc -o main
./main
```

You can run one, two, or all the commands below to `test` your code, `stylecheck` your code's design, or `formatcheck` your work. Kindly make sure that you have compiled and executed your code before issuing any of the commands below to avoid errors.

```
make test
make stylecheck
make formatcheck
```

A faster way of running all these tests uses the `all` parameter.

```
make all
```

# Submission

We recommend pushing to Github frequently to back up your work.
