#include "Ice.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice") {

}

Ice::~Ice(void) {

}

Ice::Ice(const Ice& source) : AMateria("ice"){
  (void)source;
}

Ice& Ice::operator=(const Ice &source) {
  (void)source;
  return *this;
}

AMateria* Ice::clone(void) const {
  return new Ice;
}

void Ice::use(ICharacter &target) {
  std::cout
    << "* shoots an ice bolt at " << target.getName()
    << " *" << std::endl;
}

