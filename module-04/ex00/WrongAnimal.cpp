#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) {
  std::cout << "WrongAnimal default constructor" << std::endl;

  type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& source) {
  std::cout << "WrongAnimal copy constructor" << std::endl;

  *this = source;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &source) {
  std::cout << "WrongAnimal copy assignment operator" << std::endl;

  if (this == &source)
    return *this;

  this->type = source.type;

  return *this;
}

WrongAnimal::~WrongAnimal(void) {
  std::cout << "WrongAnimal destructor" << std::endl;
}

void WrongAnimal::makeSound(void) const {
  std::cout << "WrongAnimal making sound" << std::endl;
}

const std::string& WrongAnimal::getType(void) const {
  return type;
}

