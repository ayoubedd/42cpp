#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
  Scavtrap one("One");
  Scavtrap two("Two");

  std::cout << "----------" << std::endl;

  one.attack("Two");
  two.takeDamage(one.getAttackDamage());

  std::cout << "----------" << std::endl;

  std::cout << one << std::endl;
  std::cout << two << std::endl;

  two.beRepaired(10);

  std::cout << "----------" << std::endl;

  std::cout << one << std::endl;
  std::cout << two << std::endl;

  one.guardGate();

  std::cout << "----------" << std::endl;
}
