#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) {
  std::cout << "ClapTrap default constructor" << std::endl;

  this->name = "unamed";
  this->hitPoints = ClapTrap::_hitPoints;
  this->energy = ClapTrap::_energy;
  this->attackDamage = ClapTrap::_attackDamage;
}

ClapTrap::ClapTrap(const std::string& name)  {
  std::cout << "ClapTrap single argument constructor" << std::endl;

  this->name = name;
  this->hitPoints = ClapTrap::_hitPoints;
  this->energy = ClapTrap::_energy;
  this->attackDamage = ClapTrap::_attackDamage;
}

ClapTrap::ClapTrap(const ClapTrap& source) {
  std::cout << "ClapTrap copy constructor" << std::endl;

  *this = source;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap destructor" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &source) {
  std::cout << "ClapTrap assignment operator" << std::endl;

  if (this == &source)
    return *this;

  this->name = source.name;
  this->hitPoints = source.hitPoints;
  this->energy = source.energy;
  this->attackDamage = source.attackDamage;

  return *this;
}

void ClapTrap::attack(const std::string &target) {
  if (hitPoints <= 0)
    return;

  if (energy < 1) {
    std::cout
      << "Claptrap " << name
      << " is out of energy!" << std::endl;
    return;
  }

  this->energy -= 1;

  std::cout
    << "ClapTrap " << name 
    << " attacks " << target
    << ", causing " << this->attackDamage
    << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (hitPoints <= 0)
    return;

  if (this->hitPoints - amount < 0)
    this->hitPoints = 0;
  else
    this->hitPoints -= amount;

  std::cout
    << "Claptrap " << name
    << " taking " << amount
    << " damage!"<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (hitPoints <= 0)
    return;

  if (energy < 1) {
    std::cout
      << "Claptrap " << name
      << " is out of energy!" << std::endl;
    return;
  }

  this->hitPoints += amount;
  this->energy -= 1;

  std::cout
    << "ClapTrap " << name
    << " repairing it self, +" << amount
    << " hitPoints" << std::endl;
}

const std::string& ClapTrap::getName(void) const {
  return name;
}

int ClapTrap::getHitPoints(void) const {
  return hitPoints;
}

int ClapTrap::getEnergy(void) const {
  return energy;
}

int ClapTrap::getAttackDamage(void) const {
  return attackDamage;
}

std::ostream& operator<<(std::ostream& stream, const ClapTrap& claptrap) {
  std::cout << "NAME: " << claptrap.getName() << std::endl;
  std::cout << "HITP: " << claptrap.getHitPoints() << std::endl;
  std::cout << "ENRG: " << claptrap.getEnergy() << std::endl;
  std::cout << "ATDM: " << claptrap.getAttackDamage() << std::endl;;
  std::cout << "----------";
  return stream;
}

