#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <string>
#include <stdexcept>

class Bureaucrat {
  public:
    Bureaucrat(void);
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat& source);
    ~Bureaucrat(void);

    int getGrade(void) const;
    const std::string& getName(void) const;

    void incrementGrade(void);
    void decremetnGrade(void);

    class GradeTooHighExeption : public std::exception {
      public:
        virtual const char* what(void) const throw();
    }; 

    class GradeTooLowExeption : public std::exception {
      public:
        virtual const char* what(void) const throw();
    }; 

  private:
    int _grade;
    const std::string _name;
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& instance);

#endif // !__BUREAUCRAT_HPP__
