#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string	_name;
public:
	PresidentialPardonForm();
	//PresidentialPardonForm(std::string name);
	//PresidentialPardonForm(const PresidentialPardonForm &org);
	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm &org);
};

PresidentialPardonForm::PresidentialPardonForm(): AForm("default", 145, 137)
{
	std::cout << "PresidentialPardonForm default creator" << std::endl;
	_name = "default";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

#endif
