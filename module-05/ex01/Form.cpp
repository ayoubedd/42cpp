#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form(void)
  : _name("unamed"),
  _gradeToSign(150),
  _gradeToExec(150),
  _signed(false) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExec)
  : _name(name),
  _gradeToSign(gradeToSign),
  _gradeToExec(gradeToExec),
  _signed(false)
{
  if (_gradeToSign < 1 || _gradeToExec < 1)
    throw Form::GradeTooHighException();
  if (_gradeToSign > 150 | _gradeToExec > 150)
    throw Form::GradeTooLowException();
}

Form::Form(const Form& src)
  : _name(src._name),
  _gradeToSign(src._gradeToSign),
  _gradeToExec(src._gradeToExec),
  _signed(src._signed)
{
  if (_gradeToSign < 1 || _gradeToExec < 1)
    throw Form::GradeTooHighException();
  if (_gradeToSign > 150 | _gradeToExec > 150)
    throw Form::GradeTooLowException();
}

Form& Form::operator=(const Form &source) {
  if (this == &source)
    return *this;

  this->_signed = source._signed;
  return *this;
}

Form::~Form(void) {

}

void Form::beSigned(const Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() > _gradeToSign)
    throw Form::GradeTooLowException();
  
  _signed = true;
}

const std::string& Form::getName(void) const {
  return _name;
}

int Form::getGradetoSign(void) const {
  return _gradeToSign;
}

int Form::getGradetoExec(void) const {
  return _gradeToExec;
}

bool Form::getSign(void) const {
  return _signed;
}

const char* Form::GradeTooHighException::what() const throw() {
  return "Grade too HIGH for the form";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "Grade too LOW for the form";
}

std::ostream& operator<<(std::ostream& stream, const Form& form) {
  std::cout << "Form name: " << form.getName() << std::endl;
  std::cout << "Form grade to sign: " << form.getGradetoSign() << std::endl;
  std::cout << "Form grade to exec: " << form.getGradetoExec() << std::endl;
  std::cout << "Form status: ";
  if (form.getSign() == true)
      std::cout << "signed";
  else
      std::cout << "unsigned";
  return stream;
}

