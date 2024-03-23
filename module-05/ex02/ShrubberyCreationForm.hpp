#ifndef __SHRUBBERYCREATIONFORM_HPP__
#define __SHRUBBERYCREATIONFORM_HPP__

#include "Form.hpp"

class ShrubberyCreationForm : public Form {
  public:
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(const ShrubberyCreationForm& src);
    ShrubberyCreationForm(const std::string& target);
    ~ShrubberyCreationForm(void);

    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);

    void execute(Bureaucrat const& executor) const;

  private:
    std::string _target;
};
#endif // !__SHRUBBERYCREATIONFORM_HPP__
