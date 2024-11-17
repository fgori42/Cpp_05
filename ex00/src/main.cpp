#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat jon("jon", 151);
	Bureaucrat pon("pon", 51);
	try
	{
		jon.inmcrement();
	}
	catch (std::exception &error)
	{
		std::cerr << error.what() << std::endl;
	}
}