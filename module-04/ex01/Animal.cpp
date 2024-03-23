#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) {
  std::cout << "Animal default constructor" << std::endl;

  type = "Animal";
}

Animal::Animal(const Animal& source) {
  std::cout << "Animal copy constructor" << std::endl;

  *this = source;
}

Animal& Animal::operator=(const Animal &source) {
  std::cout << "Animal copy assignment operator" << std::endl;

  if (this == &source)
    return *this;

  this->type = source.type;

  return *this;
}

Animal::~Animal(void) {
  std::cout << "Animal destructor" << std::endl;
}

void Animal::makeSound(void) const {
  std::cout << "Animal making sound" << std::endl;
}

const std::string& Animal::getType(void) const {
  return type;
}

