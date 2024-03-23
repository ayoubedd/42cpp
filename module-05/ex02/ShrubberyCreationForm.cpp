#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(void)
  : Form("ShrubberyCreationForm", 145, 137), _target("undefined") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
  : Form("ShrubberyCreationForm", 145, 137),
  _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
  : Form("ShrubberyCreationForm", 145, 137),
  _target(src._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
  if (this == &src)
    return *this;

  _target = src._target;
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
  Form::execute(executor);

  std::fstream file;

  file.open((_target + "_shrubbery").c_str(), std::ios::out | std::ios::app);

  if (!file.is_open())
    return ;

  file << "     ccee88oo" << std::endl;
  file << "  C8O8O8Q8PoOb o8oo" << std::endl;
  file << " dOB69QO8PdUOpugoO9bD" << std::endl;
  file << "CgggbU8OU qOp qOdoUOdcb" << std::endl;
  file << "    6OuU  /p u gcoUodpP" << std::endl;
  file << "      \\//  /douUP" << std::endl;
  file << "        \\////" << std::endl;
  file << "         |||/" << std::endl;
  file << "         |||/" << std::endl;
  file << "         |||||" << std::endl;
  file << "   .....//||||....\n" << std::endl;

  file.close();
}

