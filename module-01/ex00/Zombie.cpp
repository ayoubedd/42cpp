#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {}

Zombie::Zombie(std::string name) {
  this->name = name;
}

Zombie::~Zombie() {
  std::cout << this->name << ": Destroyed..." << std::endl;
}

void Zombie::announce(void) {
  std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

