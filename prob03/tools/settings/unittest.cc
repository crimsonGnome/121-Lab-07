#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../cppaudit/gtest_ext.h"
#include "../../fib.h"
#include <vector>
#include "string"

using ::testing::HasSubstr;

void BaseCaseTestZero() {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(Fibonacci(0), 0) << "    Fibonacci(0) should return 0, a base case.";
  });  
}

TEST(Fib, BaseCaseTestZero) {
  ASSERT_EXIT((BaseCaseTestZero(),exit(0)),::testing::ExitedWithCode(0),".*")
        << "    Should not crash or infinitely loop.";
    BaseCaseTestZero();
}

void BaseCaseTestOne() {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(Fibonacci(1), 1) << "    Fibonacci(1) should return 1, a base case.";
  });  
}

TEST(Fib, BaseCaseTestOne) {
  ASSERT_EXIT((BaseCaseTestOne(), exit(0)), ::testing::ExitedWithCode(0),
              ".*")
      << "    Should not crash or infinitely loop.";
  BaseCaseTestOne();
}

void FibOfTwoReturnsOne() {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(Fibonacci(2), 1)
        << "    Fibonacci(2) should return 1, which is Fibonacci(1) + Fibonacci(0).";
  });  
}

TEST(Fib, FibOfTwoReturnsOne) {
  ASSERT_EXIT((FibOfTwoReturnsOne(), exit(0)), ::testing::ExitedWithCode(0),
              ".*")
      << "    Should not crash or infinitely loop.";
  FibOfTwoReturnsOne();
}

void FibonacciTest() {
   std::vector<int> fibs = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233,
                            377, 610, 987, 1597, 2584, 4181, 6765, 10946,
                            17711, 28657, 46368, 75025, 121393, 196418,
                            317811, 514229, 832040, 1346269, 2178309,
                            3524578, 5702887, 9227465, 14930352, 24157817,
                            39088169, 63245986 };
  for (int a = 2; a < 40; a++) {
    ASSERT_DURATION_LE(3, {
      ASSERT_EQ(Fibonacci(a), fibs[a])
          << "    Fibonacci(" << (a) << ") should return " << fibs[a];
    });
  } 
}

TEST(Fib, FibonacciTest) {
  ASSERT_EXIT((FibonacciTest(), exit(0)), ::testing::ExitedWithCode(0),
              ".*")
      << "    Should not crash or infinitely loop.";
  FibonacciTest();
}

void ExecutesAndExits() {
    ASSERT_EXECEXIT("main", "1", /* seconds */ 3) << "    main should ask for a "
      "number and get Fibonacci of that number. Your program did not exit "
      "after entering the input \"1\".";
}

TEST(MainTest, ExecutesAndExits) {
  ASSERT_EXIT((ExecutesAndExits(), exit(0)), ::testing::ExitedWithCode(0),
              ".*")
      << "    Should not crash or infinitely loop.";
  ExecutesAndExits();
}

void OutputFormatFirst() {
  std::string expected = "Enter a number n: "
                         "The 21st number in the Fibonacci Sequence is: 10946";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", "21", HasSubstr(expected)) << "    main should "
        "ask for a number, then for input \"21\", print \"The 21nd number in "
        "the Fibonacci Sequence is: 10946\". Make sure to follow the format "
        "from the README.";
  });  
}

TEST(MainTest, OutputFormatFirst){
  ASSERT_EXIT((OutputFormatFirst(), exit(0)), ::testing::ExitedWithCode(0),
              ".*")
      << "    Should not crash or infinitely loop.";
  OutputFormatFirst();
}

void OutputFormatSecond() {
  std::string expected = "Enter a number n: "
                         "The 32nd number in the Fibonacci Sequence is: 2178309";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", "32", HasSubstr(expected)) << "    main should "
        "ask for a number, then for input \"32\", print \"The 32nd number in "
        "the Fibonacci Sequence is: 2178309\"";
  });  
}

TEST(MainTest, OutputFormatSecond){
  ASSERT_EXIT((OutputFormatSecond(), exit(0)), ::testing::ExitedWithCode(0),
              ".*")
      << "    Should not crash or infinitely loop.";
  OutputFormatSecond();
}

void OutputFormatThird() {
  std::string expected = "Enter a number n: "
                         "The 3rd number in the Fibonacci Sequence is: 2";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", "3", HasSubstr(expected)) << "    main should "
        "ask for a number, then for input \"3\", print \"The 3rd number in "
        "the Fibonacci Sequence is: 2\"";
  });  
}

TEST(MainTest, OutputFormatThird){
  ASSERT_EXIT((OutputFormatThird(), exit(0)), ::testing::ExitedWithCode(0),
              ".*")
      << "    Should not crash or infinitely loop.";
  OutputFormatThird();
}

void OutputFormatTweens() {
   std::string expected = "The 11th number in the Fibonacci Sequence is: 89";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", "11", HasSubstr(expected)) << "    main should "
        "ask for a number, then for input \"11\", print \"The 11th number in "
        "the Fibonacci Sequence is: 89\"";
  });
  expected = "The 12th number in the Fibonacci Sequence is: 144";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", "12", HasSubstr(expected)) << "    main should "
        "ask for a number, then for input \"12\", print \"The 12th number in "
        "the Fibonacci Sequence is: 144\"";
  });
  expected = "The 13th number in the Fibonacci Sequence is: 233";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", "13", HasSubstr(expected)) << "    main should "
        "ask for a number, then for input \"13\", print \"The 13th number in "
        "the Fibonacci Sequence is: 233\"";
  }); 
}

TEST(MainTest, OutputFormatTweens) {
  ASSERT_EXIT((OutputFormatTweens(), exit(0)), ::testing::ExitedWithCode(0),
              ".*")
      << "    Should not crash or infinitely loop.";
  OutputFormatTweens();
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  bool skip = true;
  for (int i = 0; i < argc; i++)
  {
    if (std::string(argv[i]) == "--noskip")
    {
      skip = false;
    }
  }
  if (skip)
  {
    ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  }
  return RUN_ALL_TESTS();
}
