#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) {}

void Zombie::setName(std::string name) {
  this->name = name;
}

Zombie::~Zombie() {
  std::cout << this->name << ": Destroyed..." << std::endl;
}

void Zombie::announce(void) {
  std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

