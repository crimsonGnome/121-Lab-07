#include <cmath>

#include "carpet.h"
#include "cpputils/graphics/image.h"

const int kMaxOrder = 6;

// You do NOT need to edit this file. //
int main() {
  int size = pow(3, kMaxOrder);
  graphics::Image image(size, size);
  int order;
  std::cout << "What order fractal? (Between 0 and 6): ";
  std::cin >> order;
  if (order < 0 || order > kMaxOrder) {
    return 1;
  }
  // Calls the recursive function from carpet.h. Fill the whole image by
  // using size of the image and starting at (0, 0).
  DrawCarpet(0, 0, size, order, image);
  image.SaveImageBmp("carpet.bmp");
  return 0;
}
