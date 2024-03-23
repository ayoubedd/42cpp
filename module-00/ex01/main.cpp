#include "PhoneBook.hpp"
#include <cstdio>
#include <iostream>
#include <string>
#include <iomanip>

int main(void)
{
  PhoneBook phonebook;
  std::string input;

  while (true) {
    std::cout << "$: ";
    std::getline(std::cin, input);

    if (input == "ADD")
      phonebook.addContact();
    if (input == "SEARCH")
      phonebook.searchContact();
    if (input == "EXIT" || std::cin.eof())
      break;
  }
}

