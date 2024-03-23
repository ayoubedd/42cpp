#include "Converter.hpp"
#include <iostream>
#include <string>
#include <iomanip>

int main(int argc, char *argv[]) {

  if (argc != 2) {
    if (argc == 1)
      std::cerr << "Error: input required!" << std::endl;
    else
      std::cerr << "Error: too many arguments!" << std::endl;
    return 1;
  }

  std::string argument(argv[1]);

  if (!argument.length()) {
    std::cerr << "Error: input cannot be empty" << std::endl;
    return 1;
  }

  try {
    Converter conv(argument);
    conv.print();

    std::cout << "--" << std::endl;

    conv = "13.37f";
    std::cout << conv;

  } catch (const std::exception& ex) {
    std::cerr << "Error: " << ex.what() << std::endl;
  }

  return 0;
}

