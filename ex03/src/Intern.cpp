#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern constructor called" << std::endl; 
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern &org)
{
	*this = org;
	std::cout << "Intern clone constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &org)
{
	if (this != &org)
		*this = org;
	std::cout << "Intern operator called" << std::endl;
	return (*this);
}

const char *Intern::IsNotValid::what() const throw()
{
		return "ERROR invalid type for the Form";
}

AForm	*Intern::makeForm(std::string type, std::string _target)
{
	std::string arr[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	std::string low;

	for (std::string::size_type i = 0; i < type.length(); i++)
		low += tolower(type[i]);
	int i = 0;
	while(i < 3 && low != arr[i])
		i++;
	switch (i)
	{
	case 0:
		{
			std::cout << "Intern create " << type << std::endl;
			return new PresidentialPardonForm(_target);
		}
	case 1:
		{
			std::cout << "Intern create " << type << std::endl;
			return new RobotomyRequestForm(_target);
		}
	case 2:
		{
			std::cout << "Intern create " << type << std::endl;
			return new ShrubberyCreationForm(_target);
		}
	}
	//std::cout << "Intern can'tcreate " << type << ", it isn't a valid type of Form" << std::endl;
	throw IsNotValid();
}