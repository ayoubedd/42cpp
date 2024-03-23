#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <string>
#include <stdexcept>

#include "Form.hpp"
class Form;

class Bureaucrat {
  public:
    Bureaucrat(void);
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat& source);
    ~Bureaucrat(void);

    Bureaucrat& operator=(const Bureaucrat& src);
    int getGrade(void) const;
    const std::string& getName(void) const;

    void incrementGrade(void);
    void decremetnGrade(void);
    void signForm(Form& form);

    class GradeTooHighExeption : public std::exception {
      public:
        virtual const char* what(void) const throw();
    }; 

    class GradeTooLowExeption : public std::exception {
      public:
        virtual const char* what(void) const throw();
    }; 

  private:
    const std::string _name;
    int _grade;
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& instance);

#endif // !__BUREAUCRAT_HPP__
