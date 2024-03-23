#include "Data.hpp"
#include <iostream>

Data::Data(void) {

}

Data::Data(const Data& src) {
  *this = src;
}

Data& Data::operator=(const Data &src) {
  if (this == &src)
    return *this;

  return *this;
}

Data::~Data(void) {

}

void Data::greeting(void) const {
  std::cout << "Hello world, oop is the worst" << std::endl;
}

