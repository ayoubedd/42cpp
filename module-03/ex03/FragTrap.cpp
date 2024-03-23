#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) {
  std::cout << "FragTrap default constructor" << std::endl;

  this->name = "unamed";
  this->hitPoints = FragTrap::_hitPoints;
  this->energy = FragTrap::_energy;
  this->attackDamage = FragTrap::_attackDamage;
}

FragTrap::FragTrap(const std::string& name) {
  std::cout << "FragTrap copy constructor" << std::endl;

  this->name = name;
  this->hitPoints = FragTrap::_hitPoints;
  this->energy = FragTrap::_energy;
  this->attackDamage = FragTrap::_attackDamage;
}

FragTrap::FragTrap(const FragTrap& src) {
  std::cout << "FragTrap copy constructor" << std::endl;

  *this = src;
}

FragTrap& FragTrap::operator=(const FragTrap &src) {
  std::cout << "FragTrap assignment operator" << std::endl;

  this->name = src.name;
  this->hitPoints = src.hitPoints;
  this->energy = src.energy;
  this->attackDamage = src.attackDamage;
  return *this;
}

void FragTrap::highFivesGuys(void) {
  std::cout << "HIGH FIVE FIVE GUYYYYYYYYYYYYS" << std::endl;
}

FragTrap::~FragTrap(void) {
  std::cout << "FragTrap destructor" << std::endl;
}
