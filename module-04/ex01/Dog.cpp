#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) {
  std::cout << "Dog default constructor" << std::endl;

  type = "Dog";
  _brain = new Brain();
}

Dog::Dog(const Dog& source) {
  std::cout << "Dog copy constructor" << std::endl;

  type = source.type;
  _brain = new Brain();
  *_brain = *source._brain;
}

Dog& Dog::operator=(const Dog& source) {
  std::cout << "Dog copy assignment operator" << std::endl;

  if (this == &source)
      return *this;

  type = source.type;

  delete _brain;
  _brain = new Brain();
  *_brain = *source._brain;

  return *this;
}

Dog::~Dog(void) {
  std::cout << "Dog destructor" << std::endl;

  delete _brain;
}

void Dog::makeSound(void) const {
  std::cout << "Woof" << std::endl;
}

