#include "Zombie.hpp"

#define ZOMBIES 10

int main(void)
{
  int i = 0;
  Zombie* zombies = zombieHorde(ZOMBIES, "XOR");

  while (i < ZOMBIES) {
    zombies[i].announce();
    i++;
  }

  delete[] zombies;
}
