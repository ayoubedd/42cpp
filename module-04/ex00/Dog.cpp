#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

Dog::Dog(void) {
  std::cout << "Dog default constructor" << std::endl;

  type = "Dog";
}

Dog::Dog(const Dog& source) {
  std::cout << "Dog copy constructor" << std::endl;

  *this = source;
}

Dog& Dog::operator=(const Dog& source) {
  std::cout << "Dog copy assignment operator" << std::endl;

  if (this == &source)
      return *this;

  this->type = source.type;

  return *this;
}

Dog::~Dog(void) {
  std::cout << "Dog destructor" << std::endl;
}

void Dog::makeSound(void) const {
  std::cout << "Woof" << std::endl;
}

