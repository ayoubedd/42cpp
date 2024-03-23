#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include "Form.hpp"

class Intern {
  public:
    typedef Form* (*routinePtr)(const std::string&);

    Intern(void);
    Intern(const Intern& src);
    ~Intern(void);
    
    Intern& operator=(const Intern& src);

    Form* makeForm(const std::string& formName, const std::string& target);


  private:
    static routinePtr routines[3];

    static Form* makePredencialPardonForm(const std::string& target);
    static Form* makeShrubberyCreationForm(const std::string& target);
    static Form* makeRobotomyRequestForm(const std::string& target);
};

#endif // !__INTERN_HPP__
