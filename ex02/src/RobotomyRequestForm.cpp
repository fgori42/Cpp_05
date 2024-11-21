#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", 72, 45)
{
	_target = "default";
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &org): AForm("RobotomyRequest", 72, 45)
{
	_target = org._target;
	std::cout << "RobotomyRequestForm clone constructor called new targhet: " << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string _starget): AForm("RobotomyRequest", 72, 45)
{
	_target = _starget;
	std::cout << "RobotomyRequestForm constructor called target: " << _target << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getStatus())
		throw AForm::IsnSignedForm();
	if (this->getExeGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();
	std::cout << "BzzzzZZZZZ " << std::endl << "BZZZZZZZZZzzzzzzzzzz...bZZZZZZZ" << std::endl;
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " wasn't robotomized" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &org)
{
	if (this != &org)
		_target = org._target;
	std::cout << "RobotomyRequestForm clone operator called" << std::endl;
	return(*this);
}