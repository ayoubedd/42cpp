#ifndef  __FORM_HPP__
#define  __FORM_HPP__

#include "Bureaucrat.hpp"
class Bureaucrat;

#include <string>
#include <stdexcept>

class Form {
  public:
    Form(void);
    Form(const std::string& name, int gradeToSign, int gradeToExec);
    Form(const Form& source);
    ~Form(void);

    Form& operator=(const Form& source);

    const std::string& getName(void) const;
    int getGradetoSign(void) const;
    int getGradetoExec(void) const;
    bool getSign(void) const;

    void beSigned(const Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception {
      public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        virtual const char* what() const throw();
    };

  private:
    const std::string _name;
    const int _gradeToSign;
    const int _gradeToExec;
    bool _signed;
};

std::ostream& operator<<(std::ostream& stream, const Form& form);

#endif // ! __FORM_HPP__
