#include "PhoneBook.hpp"
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

PhoneBook::PhoneBook(void) : count(-1) {}

void getInput(const std::string &prompt, std::string &input) {
  while (true) {
    if (std::cin.eof())
      break;
    std::cout << prompt;
    std::getline(std::cin, input);
    if (!input.empty())
      break;
  }
}

void PhoneBook::addContact(void) {
  std::string feild;

  if (count < 7)
    count++;

  getInput("FIRST NAME\t: ", feild);
  contacts[count].setFirstName(feild);

  getInput("LAST NAME\t: ", feild);
  contacts[count].setLastName(feild);

  getInput("NICKNAME\t: ", feild);
  contacts[count].setNickName(feild);

  getInput("PHONE NUMBER\t: ", feild);
  contacts[count].setPhoneNumber(feild);

  getInput("DARKEST SECRET\t: ", feild);
  contacts[count].setDarkestSecret(feild);
}

void printFeild(const std::string &str) {
  std::cout << std::setw(10);
  if (str.length() > 10) {
    std::cout << std::setw(9);
    std::cout << std::string(str, 0, 9) << '.';
  } else {
    // int width = (10 - str.length()) / 2;
    // std::cout << std::setw(str.length() + width) << str;
    // while (width + str.length() < 10)
      // std::cout << " ", width++;
    std::cout << str;
  }
  std::cout << "|";
}

void printTableRow(int idx, Contact contact) {
  std::stringstream stream;
  std::string index;

  stream << idx;
  stream >> index;

  std::cout << "\t|";
  printFeild(index);
  printFeild(contact.getFirstName());
  printFeild(contact.getLastName());
  printFeild(contact.getNickName());
  std::cout << std::endl;
}

void PhoneBook::printContactsTable(void) const {
  int i = 0;

  std::cout << "\t---------------------------------------------" << std::endl
            << "\t|";

  printFeild("INDEX");
  printFeild("FIRST");
  printFeild("LAST");
  printFeild("NICK");

  std::cout << std::endl
            << "\t---------------------------------------------" << std::endl;

  while (count >= 0 && i <= count) {
    printTableRow(i, contacts[i]);
    i++;
  }

  std::cout << "\t---------------------------------------------" << std::endl;
}

void printContact(const Contact &contact) {
  std::cout << "FIRST NAME\t: " << contact.getFirstName() << std::endl
            << "LAST NAME\t: " << contact.getLastName() << std::endl
            << "NICKNAME\t: " << contact.getNickName() << std::endl
            << "PHONE\t\t: " << contact.getPhoneNumber() << std::endl
            << "DARKEST SECRET\t: " << contact.getPhoneNumber() << std::endl;
}

void PhoneBook::searchContact(void) const {
  std::string input;

  printContactsTable();

  while (true) {
    std::cout << "INDEX: ";

    std::getline(std::cin, input);
    if (std::cin.eof())
      break;

    if (input.empty()) {
      std::cout << "ERROR: INPUT CANNOT BE EMPTY" << std::endl;
      return;
    }

    if (input.find_first_not_of("0123456789") != std::string::npos) {
      std::cout << "ERROR: INPUT IS NOT A NUMBER" << std::endl;
      return;
    }

    int index = std::atoi(input.c_str());
    if (std::atoi(input.c_str()) > count) {
      std::cout << "ERROR: INDEX OUT OF RANGE" << std::endl;
      return;
    }

    printContact(contacts[index]);
    break;
  }
}
