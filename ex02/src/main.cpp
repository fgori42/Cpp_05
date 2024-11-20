#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat	john("Paolo", 50);
	Bureaucrat	ad("Augusto de'Marinis", 10);
	PresidentialPardonForm	bt;
	AForm		c("c14", 30, 110);
	try
	{
		AForm		tol("tolusso", 151, 50);
	}
	catch (std::exception &error)
	{
		std::cerr << error.what() << std::endl;
	}
	std::cout << john;
	std::cout << bt;
	std::cout << std::endl;
	john.signForm(bt);
	john.signForm(bt);
	john.signForm(c);
	ad.signForm(c);
	return(0);
}