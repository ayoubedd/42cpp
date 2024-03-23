#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

int main(void)
{
  try {
    Form form("FormA", 10, 10);
    Bureaucrat bureaucrat("Josh", 10);

    std::cout << bureaucrat << std::endl;

    std::cout << "-----" << std::endl;

    std::cout << form << std::endl;

    std::cout << "-----" << std::endl;

    bureaucrat.signForm(form);

    std::cout << "-----" << std::endl;

    std::cout << form << std::endl;
  } catch (std::exception& ex) {
    std::cout << "EXCEPTION: " << ex.what() << std::endl;
  }

  std::cout << "------------------" << std::endl;

  try {
    Form form("FormB", 10, 10);
    Bureaucrat bureaucrat("Jack", 11);

    std::cout << bureaucrat << std::endl;

    std::cout << "-----" << std::endl;

    std::cout << form << std::endl;

    std::cout << "-----" << std::endl;

    bureaucrat.signForm(form);

    std::cout << "-----" << std::endl;

    std::cout << form << std::endl;
  } catch (std::exception& ex) {
    std::cout << "EXCEPTION: " << ex.what() << std::endl;
  }

  std::cout << "------------------" << std::endl;

  try {
    Form form("FormC", 0, 0);
    Bureaucrat bureaucrat("Mosh", 11);

    std::cout << bureaucrat << std::endl;

    std::cout << "-----" << std::endl;

    std::cout << form << std::endl;

    std::cout << "-----" << std::endl;

    bureaucrat.signForm(form);
  } catch (std::exception& ex) {
    std::cout << "EXCEPTION: " << ex.what() << std::endl;
  }

  std::cout << "------------------" << std::endl;

  try {
    Form form("FormC", 151, 151);
    Bureaucrat bureaucrat("Sara", 11);

    std::cout << bureaucrat << std::endl;

    std::cout << "-----" << std::endl;

    std::cout << form << std::endl;

    std::cout << "-----" << std::endl;

    bureaucrat.signForm(form);
  } catch (std::exception& ex) {
    std::cout << "EXCEPTION: " << ex.what() << std::endl;
  }
}

