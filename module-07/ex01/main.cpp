#include "iter.hpp"
#include <iostream>

template <typename T>
void print(T &data) {
	std::cout << data << std::endl;
}

int main(void) {
  std::string names[] = {"ayoub", "amine", "khalid", "karen"};
  int ages[] = {1, 2, 3, 4};

  iter(names, 4, print);

  std::cout << "---------" << std::endl;

  iter(ages, 4, print);

	return 0;
}

