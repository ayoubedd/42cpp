#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

#define ANIMALS_COUNT 4

int main(void) {
  int i = 0;
  Animal *animals[4];

  while (i < ANIMALS_COUNT / 2) {
    animals[i] = new Cat();
    std::cout << "---" << std::endl;
    i++;
  }

  while (i < ANIMALS_COUNT) {
    animals[i] = new Dog();
    std::cout << "---" << std::endl;
    i++;
  }

  std::cout << "--------------" << std::endl;

  std::cout << "---" << std::endl;

  i = 0;
  while (i < ANIMALS_COUNT) {
    delete animals[i];
    std::cout << "---" << std::endl;
    i++;
  }

  {
    Animal *one = new Dog();
    Animal *two = new Dog();

    std::cout << "---" << std::endl;

    *one = *two;

    std::cout << "---" << std::endl;

    delete one;
    delete two;
  }
}
