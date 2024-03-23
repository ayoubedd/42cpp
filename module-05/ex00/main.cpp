#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main(void)
{
  // TEST 1
  try {
    Bureaucrat josh("Josh", 10);
    std::cout << josh << std::endl;

    std::cout << "-----" << std::endl;

    josh.incrementGrade();
    std::cout << "incrementing grade" << std::endl;
    std::cout << josh << std::endl;

    std::cout << "-----" << std::endl;

    josh.decremetnGrade();
    std::cout << "decrementing grade" << std::endl;
    std::cout << josh << std::endl;

  } catch (std::exception& ex) {
    std::cout << "EXCEPTION: " << ex.what() << std::endl;
  }

  std::cout << "---------------" << std::endl;

  // TEST 2
  try {
    Bureaucrat josh("Josh", 0);

  } catch (std::exception& ex) {
    std::cout << "EXCEPTION: " << ex.what() << std::endl;
  }

  std::cout << "---------------" << std::endl;

  // TEST 3
  try {
    Bureaucrat josh("Josh", 151);

  } catch (std::exception& ex) {
    std::cout << "EXCEPTION: " << ex.what() << std::endl;
  }
}

