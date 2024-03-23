#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure") {

}

Cure::~Cure(void) {

}

Cure::Cure(const Cure& source) : AMateria("cure") {
  (void)source;
}

Cure& Cure::operator=(const Cure &source) {
  (void)source;
  return *this;
}

AMateria* Cure::clone(void) const {
  return new Cure;
}

void Cure::use(ICharacter &target) {
  std::cout
    << "* heals " << target.getName()
    << "'s wounds *" << std::endl;
}

