#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void) {
  std::cout << "DiamondTrap default constructor" << std::endl;

  this->name = "unamed";
  this->hitPoints = FragTrap::_hitPoints;
  this->energy = Scavtrap::_energy;
  this->attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) {
  std::cout << "DiamondTrap copy constructor" << std::endl;

  *this = src;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &src) {
  std::cout << "DiamondTrap assignment operator" << std::endl;

  if (this == &src)
    return *this;

  this->name = src.name;
  this->hitPoints = src.hitPoints;
  this->energy = src.energy;
  this->attackDamage = src.attackDamage;
  this->ClapTrap::name = src.ClapTrap::name;

  return *this;
}

DiamondTrap::DiamondTrap(const std::string& name) {
  std::cout << "DiamondTrap single argument constructor" << std::endl;

  this->name = name;
  this->hitPoints = FragTrap::_hitPoints;
  this->energy = Scavtrap::_energy;
  this->attackDamage = FragTrap::_attackDamage;
  ClapTrap::name = name + "_clap_name";
}

void DiamondTrap::attack(const std::string &target) {
  Scavtrap::attack(target);
}

void DiamondTrap::whoAmI(void) const {
  std::cout
    << "DiamondTrap name '" << name
    << "', ClapTrap name '" << ClapTrap::name
    << "'" << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
  std::cout << "DiamondTrap destructor" << std::endl;
}

