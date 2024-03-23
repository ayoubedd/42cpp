#include "ScavTrap.hpp"
#include <iostream>

Scavtrap::Scavtrap(void) {
  std::cout << "ScavTrap default constructor" << std::endl;

  this->name = "unamed";
  this->hitPoints = Scavtrap::_hitPoints;
  this->energy = Scavtrap::_energy;
  this->attackDamage = Scavtrap::_attackDamage;
}

Scavtrap::Scavtrap(const std::string& name) {
  std::cout << "ScavTrap single argument constructor" << std::endl;

  this->name = name;
  this->hitPoints = Scavtrap::_hitPoints;
  this->energy = Scavtrap::_energy;
  this->attackDamage = Scavtrap::_attackDamage;
}

Scavtrap::Scavtrap(const Scavtrap& src) {
  std::cout << "ScavTrap copy constructor" << std::endl;

  *this = src;
}

Scavtrap::~Scavtrap(void) {
  std::cout << "ScavTrap destructor" << std::endl;
}

Scavtrap& Scavtrap::operator=(const Scavtrap &src) {
  std::cout << "ScavTrap assignment operator" << std::endl;

  if (this == &src)
    return *this; 

  this->name = src.name;
  this->hitPoints = src.hitPoints;
  this->energy = src.energy;
  this->attackDamage = src.attackDamage;

  return *this;
}

void Scavtrap::attack(const std::string &target) {
  if (hitPoints <= 0)
    return;

  if (energy < 1) {
    std::cout
      << "ScavTrap " << name
      << " is out of energy!" << std::endl;
    return;
  }

  this->energy -= 1;

  std::cout
    << "ScavTrap " << name 
    << " attacks " << target
    << ", causing " << this->attackDamage
    << " points of damage!" << std::endl;
}

void Scavtrap::guardGate(void) {
  std::cout << "ScavTrap is in Gate keeper mode now" << std::endl;
}

