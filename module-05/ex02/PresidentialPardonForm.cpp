#include "PresidentialPardonForm.hpp"
#include "Form.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void)
  : Form("PresidentialPardonForm", 25, 5), _target("undefined") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
  : Form("PresidentialPardonForm", 25, 5),
  _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
  : Form("PresidentialPardonForm", 25, 5),
  _target(src._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
  if (this == &src)
    return *this;

  _target = src._target;
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
  Form::execute(executor);

  std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

