#include "MutantStack.hpp"
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <stack>

int main(void) {
  typedef int dataType;
  typedef MutantStack<dataType> Container;
  Container container;

  int i = 0;
  std::srand(time(NULL));
  while (i < std::rand() % 100) {
    container.push(std::rand() % 101);
    i++;
  }

  std::cout << "Size before: " << container.size() << std::endl;

  i = 0;
  while (i < std::rand() % static_cast<int>(container.size())) {
    container.pop();
    i++;
  }

  std::cout << "Poped " << i << " elements" << std::endl;

  std::cout << "Size after: " << container.size() << std::endl;

  std::cout << "---------" << std::endl;

  {
    Container::iterator it = container.begin();
    Container::iterator ite = container.end();

    while (it != ite) {
      std::cout << "--> " << *it << std::endl;
      it++;
    }
  }

  std::cout << "---------" << std::endl;

	{
		MutantStack<int> tmp(container);

		std::cout << "Top: " << tmp.top() << std::endl;
	}

  std::cout << "---------" << std::endl;

  std::cout << "Poped " << container.size() << " elements" << std::endl;

  while (container.size())
    container.pop();


  std::cout << "Size: " << container.size() << std::endl;

  {
    Container::iterator it = container.begin();
    Container::iterator ite = container.end();

    while (it != ite) {
      std::cout << "--> " << *it << std::endl;
      it++;
    }
  }

  return 0;
}
