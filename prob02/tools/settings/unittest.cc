#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../cppaudit/gtest_ext.h"
#include "../../cpputils/graphics/test/image_test_utils.h"
#include "../../carpet.h"

graphics::Color black(0, 0, 0);
graphics::Color white(255, 255, 255);

void CreatesOrderZeroFractal() {
  // Remove diff image before starting, so that if the test runs successfully
  // it isn't left behind as an artifact from last time.
  std::string diff_image = "expected_v_actual_0.bmp";
  remove(diff_image.c_str());

  graphics::Image actual(81, 81);
  ASSERT_DURATION_LE(3, {
    DrawCarpet(0, 0, 81, 0, actual);
  });

  graphics::Image expected(81, 81);
  expected.DrawRectangle(0, 0, 81, 81, black);

  bool match = ImagesMatch(&expected, &actual, diff_image,
      DiffType::kTypeHighlight);
  EXPECT_TRUE(match) << "For a zero order carpet with x,y of (0, 0) and size "
      "81, we would expect a black square 81x81 fom DrawCarpet. You can see "
      "the expected vs actual output with differences highlighted red at " << diff_image;
}

TEST(CarpetTest, CreatesOrderZeroFractal) {
 ASSERT_EXIT((CreatesOrderZeroFractal(),exit(0)),::testing::ExitedWithCode(0),".*")
         << "    Should not crash or infinitely loop.";
     CreatesOrderZeroFractal();
}

void StartsAtExpectedXAndY() {
    graphics::Image actual(5, 5);
      DrawCarpet(1, 2, 1, 0, actual);
      for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
          if (i == 1 && j == 2) {
            ASSERT_EQ(black, actual.GetColor(i, j)) << "The DrawCarpet function "
                "should start the upper left corner at the (x, y) passed in. For this "
                "order zero, size 1 carpet with (x, y) of (1, 2), that means only "
                "the pixel (1, 2) should be colored (using DrawRectangle with size 1)."
                "However, the pixel at (1, 2) was not black.";
          } else {
            ASSERT_EQ(white, actual.GetColor(i, j)) << "The DrawCarpet function "
                "should start the upper left corner at the (x, y) passed in. For this "
                "order 0, size 1 carpet with (x, y) of (1, 2), that means only "
                "the pixel (1, 2) should be colored. However, the pixel at ("
                << i << ", " << j << ") was colored unexpectedly.";
          }
        }
      }
}

TEST(CarpetTest, StartsAtExpectedXAndY) {
    ASSERT_EXIT((StartsAtExpectedXAndY(),exit(0)),::testing::ExitedWithCode(0),".*")
            << "    Should not crash or infinitely loop.";
        StartsAtExpectedXAndY();
}

void CreatesFirstOrderFractal() {
  // Remove diff image before starting, so that if the test runs successfully
  // it isn't left behind as an artifact from last time.
  std::string diff_image = "expected_v_actual_1.bmp";
  remove(diff_image.c_str());

  graphics::Image actual(81, 81);
  ASSERT_DURATION_LE(3, {
    DrawCarpet(0, 0, 81, 1, actual);
  });

  graphics::Image expected(81, 81);
  expected.DrawRectangle(0, 0, 81, 81, black);
  expected.DrawRectangle(27, 27, 27, 27, white);

  bool match = ImagesMatch(&expected, &actual, diff_image,
      DiffType::kTypeHighlight);
  EXPECT_TRUE(match) << "For a first order carpet with x,y of (0, 0) and size "
      "81, we would expect a central white square size 27 (which is 81/3)"
      " surrounded by black squares as a result of DrawCarpet. You can see the "
      "expected vs actual output with differences highlighted red at " << diff_image; 
}

TEST(CarpetTest, CreatesFirstOrderFractal) {
  ASSERT_EXIT((CreatesFirstOrderFractal(),exit(0)),::testing::ExitedWithCode(0),".*")
          << "    Should not crash or infinitely loop.";
      CreatesFirstOrderFractal();
}

void CreatesSecondOrderFractal() {
  // Remove diff image before starting, so that if the test runs successfully
  // it isn't left behind as an artifact from last time.
  std::string diff_image = "expected_v_actual_2.bmp";
  remove(diff_image.c_str());

  graphics::Image actual(81, 81);
  ASSERT_DURATION_LE(3, {
    DrawCarpet(0, 0, 81, 2, actual);
  })

  graphics::Image expected;
  expected.Load("tools/carpet_2.bmp");

  bool match = ImagesMatch(&expected, &actual, diff_image,
      DiffType::kTypeSideBySide);
  EXPECT_TRUE(match) << "For a 2nd order carpet with x,y of (0, 0) and size "
      "81, we would expect a central white square size 27 (which is 81/3)"
      " surrounded by 8 smaller white squares which are 9x9. You can see the "
      "expected vs actual output at " << diff_image;
}

TEST(CarpetTest, CreatesSecondOrderFractal) {
  ASSERT_EXIT((CreatesSecondOrderFractal(),exit(0)),::testing::ExitedWithCode(0),".*")
          << "    Should not crash or infinitely loop.";
      CreatesSecondOrderFractal();
}

void CreatesForthOrderFractal() {
  // Remove diff image before starting, so that if the test runs successfully
    // it isn't left behind as an artifact from last time.
    std::string diff_image = "expected_v_actual_4.bmp";
    remove(diff_image.c_str());
  
    graphics::Image actual(81, 81);
    ASSERT_DURATION_LE(3, {
      DrawCarpet(0, 0, 81, 4, actual);
    });
  
    graphics::Image expected;
    expected.Load("tools/carpet_4.bmp");
  
    bool match = ImagesMatch(&expected, &actual, diff_image,
        DiffType::kTypeSideBySide);
    EXPECT_TRUE(match) << "For a 4nd order carpet with x,y of (0, 0) and size "
        "81, see the expected vs actual output at " << diff_image;
}

TEST(CarpetTest, CreatesForthOrderFractal) {
  ASSERT_EXIT((CreatesForthOrderFractal(),exit(0)),::testing::ExitedWithCode(0),".*")
        << "    Should not crash or infinitely loop.";
    CreatesForthOrderFractal();
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
