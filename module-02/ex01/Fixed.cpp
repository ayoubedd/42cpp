#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) {
  std::cout << "Default constructor called" << std::endl;
  value = 0;
}

Fixed::Fixed(const Fixed& source) {
  std::cout << "Copy constructor called" << std::endl;
  *this = source;
}

Fixed::Fixed(const int num) {
  std::cout << "Int constructor called" << std::endl;
  this->value = num * (1 << fractionBits);
}

Fixed::Fixed(const float num) {
  std::cout << "Float constructor called" << std::endl;
  value = std::roundf(num * (1 << fractionBits));
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &source) {
  std::cout << "Copy assignment operator called" << std::endl;
  this->value = source.value;
  return *this;
}

float Fixed::toFloat(void) const {
  return ((float)value / (1 << fractionBits));
}

int Fixed::toInt(void) const {
  return (this->value / (1 << fractionBits));
}

int Fixed::getRawBits(void) const {
  return value;
}

void Fixed::setRawBits(const int raw) {
  this->value = raw;
}

std::ostream& operator<<(std::ostream& stream,  const Fixed& num) {
  stream << num.toFloat();
  return stream;
}

