#include "Brain.hpp"
#include <iostream>

Brain::Brain(void) {
  std::cout << "Brain default constructor" << std::endl;
}

Brain::Brain(const Brain& source) {
  std::cout << "Brain copy constructor" << std::endl;
  *this = source;
}

Brain& Brain::operator=(const Brain &source) {
  std::cout << "Brain copy assignment operator" << std::endl;

  if (this == &source)
    return *this;

  int i = 0;
  while (i < 100) {
    ideas[i] = source.ideas[i];
    i++;
  }
  return *this;
}

Brain::~Brain(void) {
  std::cout << "Brain destructor" << std::endl;
}

