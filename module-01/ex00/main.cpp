#include "Zombie.hpp"

int main(void)
{
  Zombie* zombie = newZombie("One");
  zombie->announce();
  delete zombie;
  randomChump("Two");
}

