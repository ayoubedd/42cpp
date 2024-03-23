#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>

Base* generate(void) {
  switch (std::rand() % 3) {
    case 0:
			std::cout << "Creating A instance" << std::endl;
      return new A();
    case 1:
			std::cout << "Creating B instance" << std::endl;
      return new B();
    case 2:
			std::cout << "Creating C instance" << std::endl;
      return new C();
  }
  return NULL;
}

void identify(Base* p) {
	if (p == NULL) {
		std::cout << "instance pointer cannot be NULL" << std::endl;
		return ;
	}

	if (dynamic_cast<A*>(p))
		std::cout << "its a 'A' instace" << std::endl;;

	if (dynamic_cast<B*>(p))
		std::cout << "its a 'B' instace" << std::endl;;

	if (dynamic_cast<C*>(p))
		std::cout << "its a 'C' instace" << std::endl;;
}

void identify(Base& p) {
  try {
    A ptr = dynamic_cast<A&>(p);
    std::cout << "its a 'A' instace" << std::endl;;
  } catch (...) {}

  try {
    B ptr = dynamic_cast<B&>(p);
    std::cout << "its a 'B' instace" << std::endl;;
  } catch (...) {}
  
  try {
    C ptr = dynamic_cast<C&>(p);
    std::cout << "its a 'C' instace" << std::endl;;
  } catch (...) {}
}

int main(void) {

	std::srand(std::time(0));

  Base* random = generate();

	std::cout << "----" << std::endl;

  identify(random);
  identify(*random);

	std::cout << "----" << std::endl;

  identify(NULL);
	
  return 0;
}

