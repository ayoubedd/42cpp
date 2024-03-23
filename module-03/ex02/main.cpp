#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
  FragTrap one("One");
  FragTrap two("Two");

  std::cout << "------------" << std::endl;

  one.attack("Two");
  two.takeDamage(one.getAttackDamage());

  std::cout << "------------" << std::endl;

  std::cout << one << std::endl;
  std::cout << two << std::endl;

  two.beRepaired(10);

  std::cout << "------------" << std::endl;

  std::cout << one << std::endl;
  std::cout << two << std::endl;

  two.highFivesGuys();

  std::cout << "------------" << std::endl;

}
