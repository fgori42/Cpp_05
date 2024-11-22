#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib> 

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string _starget);
	RobotomyRequestForm(const RobotomyRequestForm &org);
	~RobotomyRequestForm();

	void	execute(Bureaucrat const & executor) const;

	RobotomyRequestForm &operator=(const RobotomyRequestForm &org);
};

#endif