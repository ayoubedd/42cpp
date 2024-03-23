#include "Point.hpp"
#include <iostream>

int main(void) {
  Point A(0, 0);
  Point B(8, 8);
  Point C(12, 0);

  Point X(10, 4);

  if (bsp(A, B, C, X))
    std::cout << "Point X is inside the triangle ABC" << std::endl;
  else
    std::cout << "Point X is not inside the triangle ABC" << std::endl;
  return 0;
}
