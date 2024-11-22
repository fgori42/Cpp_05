#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat	ad("Augusto de'Marinis", 5);
	AForm		*bt = new PresidentialPardonForm("geller");
	//PresidentialPardonForm ji("geller");

	//bt = &ji;
	try
	{
		AForm		tol("tolusso", 151, 50);
	}
	catch (std::exception &error)
	{
		std::cerr << error.what() << std::endl;
	}
	std::cout << *bt;
	std::cout << std::endl;
	ad.signForm(*bt);
	std::cout << std::endl;
	ad.executeForm(*bt);
	//delete(bt);
	bt = new RobotomyRequestForm("luca");
	std::cout << std::endl;
	std::cout << std::endl;
	ad.signForm(*bt);
	ad.executeForm(*bt);
	ad.executeForm(*bt);
	ad.executeForm(*bt);
	ad.executeForm(*bt);
	ad.executeForm(*bt);
	ad.executeForm(*bt);
	ad.executeForm(*bt);
	
	return(0);
}