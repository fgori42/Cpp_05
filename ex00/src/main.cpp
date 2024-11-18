#include "Bureaucrat.hpp"

int main()
{
	//try
	//{
	//	Bureaucrat jon("jon", 151);
	//}
	//catch (std::exception &error)
	//{
	//	std::cerr << error.what() << std::endl;
	//}
	
	Bureaucrat jon("Michael", 1);
	
	try
	{
		jon.increment();
	}
	catch (std::exception &error)
	{
		std::cerr << error.what() << std::endl;
	}
	return(0);
}