#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name) {
  int i = 0;
  Zombie* zombies = new Zombie[n];

  while (i < n) {
    zombies[i].setName(name);
    i++;
  }

  return zombies;
}
