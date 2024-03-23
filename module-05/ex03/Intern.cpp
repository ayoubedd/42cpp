#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Form.hpp"
#include <iostream>

Intern::Intern(void) {}

Intern::Intern(const Intern& src) {
  (void)src;
}

Intern& Intern::operator=(const Intern &src) {
  if (this == &src)
    return *this;

  return *this;
}

Intern::~Intern(void) {}

Form* Intern::makeForm(const std::string &formName, const std::string& target) {
  Form* form = NULL;
  std::string forms[] = {"shrubbery creation", "robotomy request" ,"presidential pardon"};

  for (int i = 0; i < 3; i++) {
    if (forms[i] == formName) {
      form = routines[i](target);
      std::cout << "Intern creates " << form->getName() << std::endl;
      break;
    }
  }

  if (!form)
    std::cout << "Intern couldn't found the form" << std::endl;
  return form;
}

Form* Intern::makePredencialPardonForm(const std::string& target) {
  return new PresidentialPardonForm(target);
}

Form* Intern::makeShrubberyCreationForm(const std::string& target) {
  return new ShrubberyCreationForm(target);
}

Form* Intern::makeRobotomyRequestForm(const std::string& target) {
  return new RobotomyRequestForm(target);
}

Intern::routinePtr Intern::routines[] = {
  &Intern::makeShrubberyCreationForm,
  &Intern::makeRobotomyRequestForm,
  &Intern::makePredencialPardonForm
};

