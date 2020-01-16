#include <iostream>

#include "is_triangle.hpp"

int main() {
  // both expected to print '1'
  std::cout << (is_triangle(1.0, 1.0, 2.0, 1.0, 2.0, 2.0) == true) << std::endl;
  std::cout << (is_triangle(1.0, 0.0, 2.0, 0.0, 2.0, 0.0) == false) << std::endl;

  return 0;
}
