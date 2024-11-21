#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidental_pardon", 25, 5)
{
	std::cout << "PresidentialPardonForm default costructor" << std::endl;
	_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidental_pardon", 25, 5)
{
	_target = target;
	std::cout << "PresidentialPardonForm costructor, target: " << _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &org): AForm("Presidental_pardon", 25, 5)
{
	_target = org._target;
	std::cout << "PresidentialPardonForm clone costructor costructor, target: " << _target << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &org)
{
	if (this != &org)
		_target = org._target;
	std::cout << "PresidentialPardonForm clone operator called" << std::endl;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	//std::cout << "grado forma : " << this->getExeGrade() << " grado buro :" << executor.getGrade() << std::endl; 
	if (!this->getStatus())
		throw AForm::IsnSignedForm();
	if (this->getExeGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor target: " << _target << std::endl;
}
