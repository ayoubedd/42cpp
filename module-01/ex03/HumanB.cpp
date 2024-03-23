#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) {
  this->name = name;
  this->weapon = NULL;
}

void HumanB::setWeapon(Weapon &weapon) {
  this->weapon = &weapon;
}

void HumanB::attack(void) const {
  if (!this->weapon) {
      std::cout << this->name << " don't have a wepon to attack with" << std::endl;
      return ;
  }
  std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}
