#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat	ad("Augusto de'Marinis", 5);
	Bureaucrat	ln("Luca Nervi", 70);
	Intern		maya;
	AForm		*bt;

	try
	{
		bt = maya.makeForm("Robotomy request", "bender");
		ln.signForm(*bt);
		ln.executeForm(*bt);
		delete(bt);
		bt = maya.makeForm("asd", "luca");
		std::cout << "ciao" << std::endl;
		ln.signForm(*bt);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	return(0);
}