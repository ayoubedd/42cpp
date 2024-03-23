#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) {
  // std::cout << "Default constructor called" << std::endl;
  value = 0;
}

Fixed::Fixed(const Fixed& source) {
  // std::cout << "Copy constructor called" << std::endl;
  *this = source;
}

Fixed::Fixed(const int num) {
  // std::cout << "Int constructor called" << std::endl;
  this->value = num * (1 << fractionBits);
}

Fixed::Fixed(const float num) {
  // std::cout << "Float constructor called" << std::endl;
  value = std::roundf(num * (1 << fractionBits));
}

Fixed::~Fixed() {
  // std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &source) {
  // std::cout << "Copy assignment operator called" << std::endl;
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

Fixed Fixed::operator+(const Fixed &other) const {
  Fixed res;
  
  res.setRawBits(this->value + other.value);
  return res;
}

Fixed Fixed::operator-(const Fixed &other) const {
  Fixed sum;

  sum.setRawBits(this->value - other.value);
  return sum;
}

Fixed Fixed::operator*(const Fixed &other) const {
  Fixed res;

  res.setRawBits((this->value * other.value) / (1 << fractionBits));
  return (res);
}

Fixed Fixed::operator/(const Fixed &other) const {
  Fixed res;

  res.setRawBits(((this->value << fractionBits) / other.value));
  return (res);
}

Fixed& Fixed::operator++() {
  this->value++;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed old(*this);

  this->value++;
  return old;
}

Fixed& Fixed::operator--() {
  this->value--;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed old(*this);

  this->value--;
  return old;
}

bool Fixed::operator>(const Fixed& other) const {
  return this->value > other.value;
}

bool Fixed::operator>=(const Fixed& other) const {
  return this->value >= other.value;
}

bool Fixed::operator==(const Fixed& other) const {
  return this->value == other.value;
}

bool Fixed::operator<(const Fixed& other) const {
  return this->value < other.value;
}

bool Fixed::operator<=(const Fixed& other) const {
  return this->value <= other.value;
}

bool Fixed::operator!=(const Fixed& other) const {
  return *this == other ? false : true;
}

Fixed& Fixed::min(Fixed& one, Fixed& two) {
  return one > two ? two : one;
}

const Fixed& Fixed::min(const Fixed& one, const Fixed& two) {
  return one.toFloat() > two.toFloat() ? two : one;
}

Fixed& Fixed::max(Fixed& one, Fixed& two) {
  return one > two ? one : two;
}

const Fixed& Fixed::max(const Fixed& one, const Fixed& two) {
  return one.toFloat() > two.toFloat() ? one : two;
}

std::ostream& operator<<(std::ostream& stream,  const Fixed& num) {
  stream << num.toFloat();
  return stream;
}

