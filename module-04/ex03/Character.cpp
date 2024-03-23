#include "Character.hpp"
#include <cstdio>
#include <iostream>

Character::Character(void) {
  _name = "unamed";

  int i = 0;
  while (i < _inventory_size) {
    _inventory[i] = NULL;
    i++;
  }
}

Character::Character(const std::string& name) {
  _name = name;

  int i = 0;
  while (i < _inventory_size) {
    _inventory[i] = NULL;
    i++;
  }
}

Character::Character(const Character& source) {
  int i = 0;

  _name = source._name;

  while (i < _inventory_size) {
    if (source._inventory[i])
      _inventory[i] = source._inventory[i]->clone();
    else
      _inventory[i] = NULL;
    i++;
  }
}

Character& Character::operator=(const Character &source) {
  if (this == &source)
    return *this;

  _name = source._name;

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

Character::~Character(void) {
  int i = 0;

  while (i < _inventory_size) {
    if (_inventory[i])
      delete _inventory[i];
    i++;
  }
}

std::string const& Character::getName(void) const {
  return _name;
}

void Character::equip(AMateria *m) {
  if (!m)
    return ;

  int i = 0;
  while (i < _inventory_size) {
    if (_inventory[i] == m) {
      std::cout << "Materia already equiped" << std::endl;
      return ;
    }
    i++;
  }

  i = 0;
  while (i < _inventory_size) {
    if (!_inventory[i]) {
      _inventory[i] = m;
      return ;
    }
    i++;
  }
  std::cout << "Materias inventory is full!" << std::endl;
}

void Character::unequip(int idx) {
  if (idx >= _inventory_size || !_inventory[idx]) {
      std::cout << "Materia not found!" << std::endl;
      return ;
  }

  _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
  if (idx >= _inventory_size || !_inventory[idx]) {
    std::cout << "* Materia not found! *" << std::endl;
    return ;
  }

  _inventory[idx]->use(target);
}

