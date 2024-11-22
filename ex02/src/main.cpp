#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat	ad("Augusto de'Marinis", 5);
	Bureaucrat	ln("Luca Nervi", 70);
	AForm		*bt = new PresidentialPardonForm("geller");
	
	std::cout << *bt;
	//ad.signForm(*bt);
	ad.executeForm(*bt);
	delete(bt);
	std::cout << std::endl;
	std::cout << std::endl;
	//delete(bt);
	bt = new RobotomyRequestForm("luca");
	std::cout << *bt;
	ln.signForm(*bt);
	ln.executeForm(*bt);
	ln.executeForm(*bt);
	ln.executeForm(*bt);
	delete(bt);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	bt = new ShrubberyCreationForm("Crismas");
	std::cout << *bt;
	ln.signForm(*bt);
	ln.executeForm(*bt);
	delete(bt);
	return(0);
}