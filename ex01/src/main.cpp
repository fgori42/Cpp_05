#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *hon;
	try
	{
		hon = new Bureaucrat("jon", 151);
	}
	catch (std::exception &error)
	{
		std::cerr << error.what() << std::endl;
	}
	std::cout << "-------" << std::endl;
	hon = new Bureaucrat("Michael", 1);
	
	try
	{
		hon->decrement();
	}
	catch (const std::exception &error)
	{
		std::cerr << error.what() << std::endl;
	}
	std::cout << *hon;
	std::cout << "-------" << std::endl;
	try
	{
		for(int i= 5; i > 0; i--)
			hon->increment();
	}
	catch (const std::exception &error)
	{
		std::cerr << error.what() << std::endl;
	}

	std::cout << *hon;
	delete(hon);
	return(0);
}