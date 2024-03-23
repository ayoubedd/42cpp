#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) {
  std::cout << "Default constructor called" << std::endl;
  this->value = 0;
}

Fixed& Fixed::operator=(const Fixed &source) {
  std::cout << "Copy assignment operator called" << std::endl;
  this->value = source.value;
  return *this;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& source) {
  std::cout << "Copy constructor called" << std::endl;
  *this = source;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->value;
}

void Fixed::setRawBits(const int raw) {
  std::cout << "setRawBits member function called" << std::endl;
  this->value = raw;
}
