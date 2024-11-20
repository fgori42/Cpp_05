#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string	_targhet;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string name);
	PresidentialPardonForm(const PresidentialPardonForm &org);
	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm &org);
};

PresidentialPardonForm::PresidentialPardonForm(): AForm("default", 25, 5)
{
	std::cout << "PresidentialPardonForm default creator" << std::endl;
	_targhet = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("default", 25, 5)
{
	_targhet = target;
	std::cout << "PresidentialPardonForm creator target: " << _targhet << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor target: " << _targhet << std::endl;
}

#endif
