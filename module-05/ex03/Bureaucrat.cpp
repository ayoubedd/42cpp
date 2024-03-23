#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void) {
  _grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name) {
  if (src._grade < 1)
    throw Bureaucrat::GradeTooHighExeption();
  if (src._grade > 150)
    throw Bureaucrat::GradeTooLowExeption();

  _grade = src._grade;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
  if (grade < 1)
    throw Bureaucrat::GradeTooHighExeption();
  if (grade > 150)
    throw Bureaucrat::GradeTooLowExeption();

  _grade = grade;
}

int Bureaucrat::getGrade(void) const {
  return _grade;
}

const std::string& Bureaucrat::getName(void) const {
  return _name;
}

void Bureaucrat::incrementGrade(void) {
  if (_grade - 1 < 1)
    throw Bureaucrat::GradeTooHighExeption();

  _grade--;
}

void Bureaucrat::decremetnGrade(void) {
  if (_grade + 1 > 150)
    throw Bureaucrat::GradeTooLowExeption();

  _grade++;
}

const char* Bureaucrat::GradeTooHighExeption::what(void) const throw() {
  return "Grade too high, cannot be greater than 1";
}

const char* Bureaucrat::GradeTooLowExeption::what(void) const throw() {
  return "Grade too low, cannot be less than 150";
}

Bureaucrat::~Bureaucrat(void) {

}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& instance) {
  std::cout
    << instance.getName() << ", bureaucrat grade "
    << instance.getGrade();
  return stream;
}

void Bureaucrat::signForm(Form& form) {
  try {
    form.beSigned(*this);
    std::cout << _name << " signed " << form.getName() << std::endl;
  } catch (const std::exception& ex) {
    std::cout
      << _name << " couldn't sign the form "
      << form.getName() << " because '" << ex.what() << "'" << std::endl;
  }
}

void Bureaucrat::executeForm(const Form &form) {
  try {
    form.execute(*this);
    std::cout << _name << " executed " << form.getName() << std::endl;
  } catch (const std::exception& ex) {
    std::cout
      << _name << " couldn't execute the Form '"
      << form.getName() << "' because '"
      << ex.what() << "'"
      << std::endl;
  }
}
