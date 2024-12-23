#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat	john("Paolo", 50);
	Bureaucrat	ad("Augusto de'Marinis", 10);
	Form		bt("b 52", 60, 100);
	Form		c("c14", 30, 110);
	try
	{
		Form		tol("tolusso", 151, 50);
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