#include "AMateria.hpp"

AMateria::AMateria(void) {
  _type = "nonset";
}

AMateria::AMateria(const AMateria& source) {
  (void)source;
}

AMateria& AMateria::operator=(const AMateria &source) {
  (void)source;
  return *this;
}

AMateria::AMateria(std::string const &type) {
  _type = type;
}

AMateria::~AMateria(void) {

}

std::string const &AMateria::getType() const {
  return _type;
}

void AMateria::use(ICharacter &target) {
  (void)target;
}

