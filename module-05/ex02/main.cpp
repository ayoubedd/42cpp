#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main(void) {
  Bureaucrat josh("Josh", 5);
  Bureaucrat karen("Karen", 140);
  Bureaucrat bob("Bob", 80);

  std::cout << josh << std::endl;
  std::cout << "---" << std::endl;
  std::cout << karen << std::endl;
  std::cout << "---" << std::endl;
  std::cout << bob << std::endl;

  std::cout << "----------" << std::endl;

  PresidentialPardonForm PPForm("Donald");
  ShrubberyCreationForm SCForm("Home");
  RobotomyRequestForm RRForm("XXIX");

  std::cout << PPForm << std::endl;
  std::cout << "---" << std::endl;
  std::cout << SCForm << std::endl;
  std::cout << "---" << std::endl;
  std::cout << RRForm << std::endl;

  std::cout << "--------------------" << std::endl;

  josh.signForm(PPForm);
  josh.executeForm(PPForm);

  std::cout << "----------" << std::endl;

  karen.signForm(SCForm);
  karen.executeForm(SCForm);
  josh.executeForm(SCForm);

  std::cout << "----------" << std::endl;

  bob.signForm(RRForm);
  bob.executeForm(RRForm);
  josh.signForm(RRForm);
  josh.executeForm(RRForm);
}
