// Name: Joseph Eggers
// CWID: 885939488
// Email: joseph.eggers@csu.fullerton.edu

#include "carpet.h"

using graphics::Color, graphics::Image;

void DrawCarpetHelper(int x, int y, int position_, int size, int order,
                      int recursiveDepth, Image& image) {
  // Base case is recrusiveDetph == Order
  // Recursive case
  if (recursiveDepth != order) {
    int Position = position_ / 3;
    int tempSize = size;
    for (int i = Position; i < size; i = i + position_) {
      for (int k = Position; k < size; k = k + position_) {
        image.DrawRectangle(i + x, k + y, Position, Position,
                            Color(255, 255, 255));
      }
    }
    // Recursive Call
    DrawCarpetHelper(x, y, Position, size, order, recursiveDepth + 1, image);
  }
}

void DrawCarpet(int x, int y, int size, int order, graphics::Image& image) {
  // Your code here to draw a carpet with top left corner at (x, y), recursive
  // order |order|, and size |size|, onto the graphics::Image provided.
  image.DrawRectangle(x, y, size, size, Color(0, 0, 0));
  DrawCarpetHelper(x, y, size, size, order, 0, image);
}
