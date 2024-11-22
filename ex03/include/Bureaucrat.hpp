#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <exception>
# include "AForm.hpp"

class AForm;

class  Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &org);
	~Bureaucrat();

	std::string	getName() const;
	int			getGrade() const;
	void		increment();
	void		decrement();
	void		signForm(AForm &form);
	void		executeForm(AForm const & form);

	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	Bureaucrat &operator=(const Bureaucrat & org);
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &buro);
#endif