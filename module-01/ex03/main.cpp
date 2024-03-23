#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main(void)
{
  Weapon weapon("knife");

  HumanA humanA("HumanA", weapon);
  HumanB humanB("HumanB");

  humanA.attack();
  humanB.attack();

  humanB.setWeapon(weapon);
  weapon.setType("molotov");

  std::cout << "------------------------" << std::endl;

  humanA.attack();
  humanB.attack();

  weapon.setType("hand");

  std::cout << "------------------------" << std::endl;

  humanA.attack();
  humanB.attack();
}
