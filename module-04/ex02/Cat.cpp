#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) {
  std::cout << "Cat default constructor" << std::endl;

  type = "Cat";
  _brain = new Brain();
}

Cat::Cat(const Cat& source) {
  std::cout << "Cat copy constructor" << std::endl;

  type = source.type;
  _brain = new Brain();
  *_brain = *source._brain;
}

Cat& Cat::operator=(const Cat& source) {
  std::cout << "Cat copy assignment operator" << std::endl;

  if (this == &source)
      return *this;

  type = source.type;

  delete _brain;
  _brain = new Brain();
  *_brain = *source._brain;

  return *this;
}

Cat::~Cat(void) {
  std::cout << "Cat destructor" << std::endl;

  delete _brain;
}

void Cat::makeSound(void) const {
  std::cout << "Meow" << std::endl;
}

