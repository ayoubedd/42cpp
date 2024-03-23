#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
  DiamondTrap One("One");
  DiamondTrap Two("Two");
  
  std::cout << "----------" << std::endl;

  One.whoAmI();
  Two.whoAmI();

  std::cout << "----------" << std::endl;

  std::cout << One << std::endl;
  std::cout << Two << std::endl;

  One.attack("Two");
  Two.takeDamage(One.getAttackDamage());


  std::cout << "----------" << std::endl;

  std::cout << One << std::endl;
  std::cout << Two << std::endl;

  Two.beRepaired(30);

  std::cout << "----------" << std::endl;

  std::cout << One << std::endl;
  std::cout << Two << std::endl;

  One.highFivesGuys();
  Two.guardGate();

  std::cout << "----------" << std::endl;

  return 0;
}
