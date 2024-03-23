#ifndef __PRESIDENTIAL_PARDON_FORM_HPP__
#define __PRESIDENTIAL_PARDON_FORM_HPP__

#include "Bureaucrat.hpp"
#include "Form.hpp"

class PresidentialPardonForm : public Form {
  public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(const std::string& name);
    PresidentialPardonForm(const PresidentialPardonForm& src);
    ~PresidentialPardonForm(void);
    
    PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
    
    void execute(Bureaucrat const& executor) const;

  private:
    std::string _target;
};

#endif // !__PRESIDENTIAL_PARDON_FORM_HPP__
