#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void) {
  std::cout << "WrongCat default constructor" << std::endl;

  type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& source) {
  std::cout << "WrongCat copy constructor" << std::endl;
  
  *this = source;
}

WrongCat& WrongCat::operator=(const WrongCat& source) {
  std::cout << "WrongCat copy assignment operator" << std::endl;

  if (this == &source)
    return *this;

  this->type = source.type;

  return *this;
}

WrongCat::~WrongCat(void) {
  std::cout << "WrongCat destructor" << std::endl;
}

void WrongCat::makeSound(void) const {
  std::cout << "Meow" << std::endl;
}

