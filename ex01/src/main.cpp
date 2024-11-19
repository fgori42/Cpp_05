#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat	john("jon", 50);
	Form		bt("b 52", 78, 100);
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
	
	return(0);
}