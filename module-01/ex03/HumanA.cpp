#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : weapon(weapon), name(name) {}

void HumanA::attack(void) const {
  std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

