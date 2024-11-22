#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &org);
	~Intern();

	AForm	*makeForm(std::string type, std::string _target);
	Intern &operator=(const Intern &org);


	class IsNotValid : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

#endif