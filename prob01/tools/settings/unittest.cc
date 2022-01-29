#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <map>
#include "../../recursion.h"
#include "../cppaudit/gtest_ext.h"
#include "string"

using ::testing::HasSubstr;
using ::testing::MatchesRegex;

void UnscrambleEmptyString() {
  std::map<std::string, bool> dictionary;
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO("", { Unscramble("", dictionary); },
                 {
                   EXPECT_EQ(your_output.size(), 0)
                       << "    The RecursiveUnscramble function should not "
                          "print anything if "
                          "the prefix is the empty string.";
                 });
  });
}

TEST(UnscrambleTest, UnscrambleEmptyString) {
  ASSERT_EXIT((UnscrambleEmptyString(), exit(0)), ::testing::ExitedWithCode(0),
              ".*")
      << "    Should not crash or infinitely loop.";
  UnscrambleEmptyString();
}

void UnscrambleSingleLetterNotInDictionary() {
  std::map<std::string, bool> dictionary;
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO("", { Unscramble("A", dictionary); },
                 {
                   ASSERT_THAT(your_output, Not(HasSubstr("A")))
                       << "    The RecursiveUnscramble function should not "
                          "print the word \"A\" "
                          "when asked to unscramble the string \"A\" and \"A\" "
                          "is not in the valid words list";
                 });
  });
}

TEST(UnscrambleTest, UnscrambleSingleLetterNotInDictionary) {
  ASSERT_EXIT((UnscrambleSingleLetterNotInDictionary(), exit(0)),
              ::testing::ExitedWithCode(0), ".*")
      << "    Should not crash or infinitely loop.";
  UnscrambleSingleLetterNotInDictionary();
}

void UnscrambleSingleLetterInDictionary() {
  std::map<std::string, bool> dictionary;
  dictionary["A"] = true;

  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO("", { Unscramble("A", dictionary); },
                 {
                   ASSERT_THAT(your_output, HasSubstr("A"))
                       << "    The RecursiveUnscramble function should print "
                          "the word \"A\" "
                          "when asked to unscramble the string \"A\" and \"A\" "
                          "is in the valid words list";
                 });
  });
}

TEST(UnscrambleTest, UnscrambleSingleLetterInDictionary) {
  ASSERT_EXIT((UnscrambleSingleLetterInDictionary(), exit(0)),
              ::testing::ExitedWithCode(0), ".*")
      << "    Should not crash or infinitely loop.";
  UnscrambleSingleLetterInDictionary();
}

void UnscrambleTwoLetterStringsAllStringsInDictionary() {
  std::map<std::string, bool> dictionary;
  dictionary["AB"] = true;
  dictionary["BA"] = true;
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO("", { Unscramble("AB", dictionary); },
                 {
                   ASSERT_THAT(your_output, HasSubstr("AB"))
                       << "    The RecursiveUnscramble function should print "
                          "the word \"AB\" "
                          "when asked to unscramble the string \"AB\" and "
                          "\"AB\" is in the valid words list";
                   ASSERT_THAT(your_output, HasSubstr("BA"))
                       << "    The RecursiveUnscramble function should print "
                          "the word \"BA\" "
                          "when asked to unscramble the string \"BA\" and "
                          "\"BA\" is in the valid words list";
                 });
  });
}

TEST(UnscrambleTest, UnscrambleTwoLetterStringsAllStringsInDictionary) {
  ASSERT_EXIT((UnscrambleTwoLetterStringsAllStringsInDictionary(), exit(0)),
              ::testing::ExitedWithCode(0), ".*")
      << "    Should not crash or infinitely loop.";
  UnscrambleTwoLetterStringsAllStringsInDictionary();
}

void UnscrambleTwoLetterStringsOnlyOneStringInDictionary() {
  std::map<std::string, bool> dictionary;
  dictionary["TO"] = true;
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO("", { Unscramble("OT", dictionary); },
                 {
                   ASSERT_THAT(your_output, HasSubstr("TO"))
                       << "    The RecursiveUnscramble function should print "
                          "the word \"TO\" "
                          "when asked to unscramble the string \"OT\" and "
                          "\"TO\" is in the valid words list";
                   ASSERT_THAT(your_output, Not(HasSubstr("OT")))
                       << "    The RecursiveUnscramble function should not "
                          "print the word \"OT\" "
                          "when asked to unscramble the string \"OT\" and "
                          "\"OT\" is not in the valid words list";
                 });
  });
}

TEST(UnscrambleTest, UnscrambleTwoLetterStringsOnlyOneStringInDictionary) {
  ASSERT_EXIT((UnscrambleTwoLetterStringsOnlyOneStringInDictionary(), exit(0)),
              ::testing::ExitedWithCode(0), ".*")
      << "    Should not crash or infinitely loop.";
  UnscrambleTwoLetterStringsOnlyOneStringInDictionary();
}

void UnscrambleManyLetterWordSomeInDictionary() {
  std::map<std::string, bool> dictionary;
  dictionary["CINEMA"] = true;
  dictionary["ICEMAN"] = true;
  dictionary["ANEMIC"] = true;
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO(
        "", { Unscramble("AEINCM", dictionary); },
        {
          ASSERT_THAT(your_output, HasSubstr("CINEMA"))
              << "    The RecursiveUnscramble function should print the word "
                 "\"CINEMA\" "
                 "when asked to unscramble the string \"AEINCM\" and "
                 "\"CINEMA\" is in the valid words list";
          ASSERT_THAT(your_output, HasSubstr("ICEMAN"))
              << "    The RecursiveUnscramble function should print the word "
                 "\"ICEMAN\" "
                 "when asked to unscramble the string \"AEINCM\" and "
                 "\"ICEMAN\" is in the valid words list";
          ASSERT_THAT(your_output, HasSubstr("ANEMIC"))
              << "    The RecursiveUnscramble function should print the word "
                 "\"ANEMIC\" "
                 "when asked to unscramble the string \"AEINCM\" and "
                 "\"ANEMIC\" is in the valid words list";
          ASSERT_THAT(your_output, Not(HasSubstr("AEINCM")))
              << "    The RecursiveUnscramble function should not print letter "
                 "combinations which are not in the word list, like "
                 "\"AEINCM\", for input \"AEINCM\"";
          ASSERT_THAT(your_output, Not(HasSubstr("AEINMC")))
              << "    The RecursiveUnscramble function should not print letter "
                 "combinations which are not in the word list, like "
                 "\"AEINMC\", for input \"AEINCM\"";
          ASSERT_THAT(your_output, Not(HasSubstr("AENIMC")))
              << "    The RecursiveUnscramble function should not print letter "
                 "combinations which are not in the word list, like "
                 "\"AENIMC\", for input \"AEINCM\"";
        });
  });
}

TEST(UnscrambleTest, UnscrambleManyLetterWordSomeInDictionary) {
  ASSERT_EXIT((UnscrambleManyLetterWordSomeInDictionary(), exit(0)),
              ::testing::ExitedWithCode(0), ".*")
      << "    Should not crash or infinitely loop.";
  UnscrambleManyLetterWordSomeInDictionary();
}

void UnscrambleWithMultipleWords_PrintsWordsInDictionary() {
  std::map<std::string, bool> dictionary;
  dictionary["CHIN"] = true;
  dictionary["INCH"] = true;
  dictionary["CHI"] = true;
  dictionary["HIC"] = true;
  dictionary["HIN"] = true;
  dictionary["ICH"] = true;
  dictionary["HI"] = true;
  dictionary["IN"] = true;
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO("", { ScrabbleSolver("HCIN", dictionary); },
                 {
                   ASSERT_THAT(your_output, MatchesRegex(".*\\bCHIN\\b.*"))
                       << "    The RecursiveUnscramble function should print "
                          "the word \"CHIN\" "
                          "when asked to unscramble the string \"HCIN\" and "
                          "\"CHIN\" is in the valid words list";
                   ASSERT_THAT(your_output, MatchesRegex(".*\\bINCH\\b.*"))
                       << "    The RecursiveUnscramble function should print "
                          "the word \"INCH\" "
                          "when asked to unscramble the string \"HCIN\" and "
                          "\"INCH\" is in the valid words list";
                   ASSERT_THAT(your_output, MatchesRegex(".*\\bCHI\\b.*"))
                       << "    The RecursiveUnscramble function should print "
                          "the word \"CHI\" "
                          "when asked to unscramble the string \"HCIN\" and "
                          "\"CHI\" is in the valid words list";
                   ASSERT_THAT(your_output, MatchesRegex(".*\\bHIC\\b.*"))
                       << "    The RecursiveUnscramble function should print "
                          "the word \"HIC\" "
                          "when asked to unscramble the string \"HCIN\" and "
                          "\"HIC\" is in the valid words list";
                   ASSERT_THAT(your_output, MatchesRegex(".*\\bHIN\\b.*"))
                       << "    The RecursiveUnscramble function should print "
                          "the word \"HIN\" "
                          "when asked to unscramble the string \"HCIN\" and "
                          "\"HIN\" is in the valid words list";
                   ASSERT_THAT(your_output, MatchesRegex(".*\\bICH\\b.*"))
                       << "    The RecursiveUnscramble function should print "
                          "the word \"ICH\" "
                          "when asked to unscramble the string \"HCIN\" and "
                          "\"ICH\" is in the valid words list";
                   ASSERT_THAT(your_output, MatchesRegex(".*\\bHI\\b.*"))
                       << "    The RecursiveUnscramble function should print "
                          "the word \"HI\" "
                          "when asked to unscramble the string \"HCIN\" and "
                          "\"HI\" is in the valid words list";
                   ASSERT_THAT(your_output, MatchesRegex(".*\\bIN\\b.*"))
                       << "    The RecursiveUnscramble function should print "
                          "the word \"IN\" "
                          "when asked to unscramble the string \"HCIN\" and "
                          "\"IN\" is in the valid words list";
                 });
  });
}

TEST(ScrabbleSolverTest, UnscrambleWithMultipleWords_PrintsWordsInDictionary) {
  ASSERT_EXIT((UnscrambleWithMultipleWords_PrintsWordsInDictionary(), exit(0)),
              ::testing::ExitedWithCode(0), ".*")
      << "    Should not crash or infinitely loop.";
  UnscrambleWithMultipleWords_PrintsWordsInDictionary();
}

void UnscrambleWithMultipleWords_DoesntPrintInvalidWords() {
  std::map<std::string, bool> dictionary;
  dictionary["CHIN"] = true;
  dictionary["INCH"] = true;
  dictionary["CHI"] = true;
  dictionary["HIC"] = true;
  dictionary["HIN"] = true;
  dictionary["ICH"] = true;
  dictionary["HI"] = true;
  dictionary["IN"] = true;
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO(
        "", { ScrabbleSolver("HCIN", dictionary); },
        {
          ASSERT_THAT(your_output, Not(MatchesRegex(".*\\bHCIN\\b.*")))
              << "    The RecursiveUnscramble function should not print letter "
                 "combinations which are not in the word list, like \"HCIN\", "
                 "for input \"HCIN\"";
          ASSERT_THAT(your_output, Not(MatchesRegex(".*\\bNH\\b.*")))
              << "    The RecursiveUnscramble function should not print letter "
                 "combinations which are not in the word list, like \"NH\", "
                 "for input \"HCIN\"";
          ASSERT_THAT(your_output, Not(MatchesRegex(".*\\bH\\b.*")))
              << "    The RecursiveUnscramble function should not print letter "
                 "combinations which are not in the word list, like \"H\", for "
                 "input \"HCIN\"";
        });
  });
}

TEST(ScrabbleSolverTest, UnscrambleWithMultipleWords_DoesntPrintInvalidWords) {
  ASSERT_EXIT((UnscrambleWithMultipleWords_DoesntPrintInvalidWords(), exit(0)),
              ::testing::ExitedWithCode(0), ".*")
      << "    Should not crash or infinitely loop.";
  UnscrambleWithMultipleWords_DoesntPrintInvalidWords();
}

void DoesNotDuplicateWordsWhenGivenRepeatedLetters() {
  std::map<std::string, bool> dictionary;
  dictionary["EYE"] = true;
  dictionary["EE"] = true;
  dictionary["YE"] = true;
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO("", { ScrabbleSolverNoDupes("EEY", dictionary); },
                 {
                   std::size_t found = your_output.find("EYE");
                   ASSERT_NE(found, std::string::npos)
                       << "    ScrabbleSolverNoDupes should "
                          "print out \"EYE\" if \"EYE\" is in the word list "
                          "and \"EEY\" was the "
                          "input.";
                   found = your_output.substr(found + 1).find("EYE");
                   ASSERT_EQ(found, std::string::npos)
                       << "   ScrabbleSolverNoDupes should "
                          "only print out \"EYE\" once for input \"EEY\". Use "
                          "the |used_words| dictionary to "
                          "keep track of words which were already printed.";
                 });
  });
}

TEST(ScrabbleSolverNoDupesTest, DoesNotDuplicateWordsWhenGivenRepeatedLetters) {
  ASSERT_EXIT((DoesNotDuplicateWordsWhenGivenRepeatedLetters(), exit(0)),
              ::testing::ExitedWithCode(0), ".*")
      << "    Should not crash or infinitely loop.";
  DoesNotDuplicateWordsWhenGivenRepeatedLetters();
}

void DoesNotDuplicateWordsWhenGivenManyRepeatedLetters() {
  std::map<std::string, bool> dictionary;
  dictionary["AA"] = true;
  dictionary["ACT"] = true;
  dictionary["ACTA"] = true;
  dictionary["AT"] = true;
  dictionary["TAA"] = true;
  dictionary["CAT"] = true;
  dictionary["TA"] = true;
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO("", { ScrabbleSolverNoDupes("AAAACT", dictionary); },
                 {
                   std::size_t found = your_output.find("CAT");
                   ASSERT_NE(found, std::string::npos)
                       << "    ScrabbleSolverNoDupes should "
                          "print out \"CAT\" if \"CAT\" is in the word list "
                          "and \"AAAACT\" was the "
                          "input.";
                   found = your_output.substr(found + 1).find("CAT");
                   ASSERT_EQ(found, std::string::npos)
                       << "   ScrabbleSolverNoDupes should "
                          "only print out \"CAT\" once for input \"AAAACT\". "
                          "Use the |used_words| dictionary to "
                          "keep track of words which were already printed.";
                 });
  });
}

TEST(ScrabbleSolverNoDupesTest,
     DoesNotDuplicateWordsWhenGivenManyRepeatedLetters) {
  ASSERT_EXIT((DoesNotDuplicateWordsWhenGivenManyRepeatedLetters(), exit(0)),
              ::testing::ExitedWithCode(0), ".*")
      << "    Should not crash or infinitely loop.";
  DoesNotDuplicateWordsWhenGivenManyRepeatedLetters();
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  bool skip = true;
  for (int i = 0; i < argc; i++) {
    if (std::string(argv[i]) == "--noskip") {
      skip = false;
    }
  }
  if (skip) {
    ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  }
  return RUN_ALL_TESTS();
}
