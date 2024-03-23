#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void) {
  int i = 0;

  while (i < _inventory_size) {
    _inventory[i] = NULL;
    i++;
  }
}

MateriaSource::MateriaSource(const MateriaSource& source) {
  int i = 0;

  while (i < _inventory_size) {
    if (source._inventory[i])
      _inventory[i] = source._inventory[i]->clone();
    else
      _inventory[i] = NULL;
    i++;
  }
}

MateriaSource& MateriaSource::operator=(const MateriaSource &source) {
  if (this == &source)
    return *this;

  int i = 0;
  while (i < _inventory_size) {
    if (_inventory[i])
      delete _inventory[i];

    if (source._inventory[i])
      _inventory[i] = source._inventory[i]->clone();
    else
      _inventory[i] = NULL;
    i++;
  }
  return *this;
}


MateriaSource::~MateriaSource(void) {
  int i = 0;

  while (i < _inventory_size) {
    if (_inventory[i])
      delete _inventory[i];
    i++;
  }
}

void MateriaSource::learnMateria(AMateria *source) {
  if (!source)
    return;

  int i = 0;
  while (i < _inventory_size) {
    if (_inventory[i] == NULL) {
      _inventory[i] = source->clone();
      return ;
    }
    i++;
  }
}

AMateria* MateriaSource::createMateria(const std::string &type) {
  int i = 0;

  while (i < _inventory_size) {
      if (_inventory[i] && _inventory[i]->getType() == type)
        return _inventory[i]->clone();
    i++;
  }
  return NULL;
}
