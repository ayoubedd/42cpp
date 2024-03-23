#ifndef __ROBOTOMYREQUESTFORM__
#define __ROBOTOMYREQUESTFORM__

#include "Bureaucrat.hpp"
#include "Form.hpp"

class RobotomyRequestForm : public Form {
  public:
    RobotomyRequestForm(void);
    RobotomyRequestForm(const RobotomyRequestForm& src);
    RobotomyRequestForm(const std::string& name);
    ~RobotomyRequestForm(void);

    RobotomyRequestForm& operator=(const RobotomyRequestForm& src);

    void execute(Bureaucrat const& executor) const;

  private:
    std::string _target;
};

#endif // !__ROBOTOMYREQUESTFORM__
