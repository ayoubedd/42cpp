#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Error: invalid amout of arguments" << std::endl;
    return EXIT_FAILURE;
  }

  try {
    BitcoinExchange atm("database.csv");
    std::ifstream inputFile(argv[1]);
    BitcoinExchange::dateValuePair dateValuePair;
    std::string line;
    bool preHeader = true;

    if (inputFile.is_open() == false)
      throw std::runtime_error("failure opening: " + std::string(argv[1]));

    while (true) {
      std::getline(inputFile, line);

      if (inputFile.eof())
        break;

      if (line.empty() == true)
        continue;

      if (preHeader == true && isValidInputHeader(line) == false)
        throw std::runtime_error("invalid header => " + line);

      if (preHeader == true) {
        preHeader = false;
        continue;
      }

      if (isValidLine(line, '|', 2) == false) {
        std::cerr << ("Error: input: invalid line => " + line) << std::endl;
        continue;
      }

      try {
        dateValuePair = parseLine(line, "|");
        double value = atm.exchange(dateValuePair);
        std::cout << dateValuePair.first << " => " << dateValuePair.second
                  << " = " << value << std::endl;
      } catch (const std::exception &exp) {
        std::cout << "Error: " << exp.what() << std::endl;
      }
    }

  } catch (const std::exception &exp) {
    std::cout << "Error: " << exp.what() << std::endl;
  }

  return EXIT_SUCCESS;
}
