#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(void)
  : Form("RobotomyRequestForm", 72, 45), _target("undefined") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
  : Form("RobotomyRequestForm", 72, 45),
  _target(target) {}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
  : Form("RobotomyRequestForm", 72, 45),
  _target(src._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
  if (this == &src)
    return *this;
  
  _target = src._target;
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {

}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
  Form::execute(executor);
  
  std::cout << "Brrrrrrrrrrrr" << std::endl;

  std::srand(time(0));
  if (std::rand() % 2 == 0)
    std::cout << _target << " has been robotomized successfully" << std::endl;
  else
    std::cout << _target << " robotomy failed" << std::endl;
}

