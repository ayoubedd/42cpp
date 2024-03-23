#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

Cat::Cat(void) {
  std::cout << "Cat default constructor" << std::endl;

  type = "Cat";
}

Cat::Cat(const Cat& source) {
  std::cout << "Cat copy constructor" << std::endl;
  
  *this = source;
}

Cat& Cat::operator=(const Cat& source) {
  std::cout << "Cat copy assignment operator" << std::endl;

  if (this == &source)
      return *this;

  this->type = source.type;

  return *this;
}

Cat::~Cat(void) {
  std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound(void) const {
  std::cout << "Meow" << std::endl;
}

