#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

int main(void) {
  Bureaucrat josh("Josh", 1);
  Intern me;

  Form* formOne = me.makeForm("presidential pardon", "Donald");
  Form* formTwo = me.makeForm("shrubbery creation", "Home");

  std::cout << "----------" << std::endl;

  std::cout << josh << std::endl;
  std::cout << "---" << std::endl;
  std::cout << *formOne << std::endl;

  std::cout << "----------" << std::endl;

  josh.signForm(*formOne);
  josh.executeForm(*formOne);

  std::cout << "---" << std::endl;

  josh.signForm(*formTwo);
  josh.executeForm(*formTwo);

  std::cout << "----------" << std::endl;

  Form* nonExisting = me.makeForm("non existing form", "Carl");
  std::cout << "PTR -> " << nonExisting << std::endl;

  return 0;
}
