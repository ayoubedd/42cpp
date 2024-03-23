#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main(void)
{
  std::vector<int> vec(6);
  std::list<int> list(6);

  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);

  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);

  try {
    std::vector<int>::iterator res = easyfind(vec, 4);
    std::cout << "RESULT:  " << *res << std::endl;
  } catch (std::exception& ex) {
    std::cerr << "ERROR: " << ex.what() << std::endl;
  }

  std::cout << "-----------" << std::endl;


  try {
		const std::vector<int> const_vec(vec);
    const std::vector<int>::const_iterator res = easyfind< std::vector<int> >(const_vec, 5);
    std::cout << "RESULT:  " << *res << std::endl;
  } catch (std::exception& ex) {
    std::cerr << "ERROR: " << ex.what() << std::endl;
  }
	
  std::cout << "-----------" << std::endl;

  try {
    std::list<int>::iterator res;

    res = easyfind< std::list<int> >(list, 1);
    std::cout << "RESULT:  " << *res << std::endl;

    res = easyfind< std::list<int> >(list, 2);
    std::cout << "RESULT:  " << *res << std::endl;

    res = easyfind< std::list<int> >(list, 3);
    std::cout << "RESULT:  " << *res << std::endl;

  } catch (std::exception& ex) {
    std::cerr << "ERROR: " <<  ex.what() << std::endl;
  }
  
}

