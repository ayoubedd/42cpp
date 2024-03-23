#include "RPN.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Error: invalid amount of arguments" << std::endl;
    return EXIT_FAILURE;
  }

  Rpn rpn;

  try {
    rpn.repl(argv[1]);
    if (rpn.stackSize() != 1)
      throw std::runtime_error("invalid polish notation");
  } catch (const std::exception &exp) {
    std::cerr << "Error: " << exp.what() << std::endl;
    return EXIT_FAILURE;
  }

  rpn.printResult();

  return EXIT_SUCCESS;
}
