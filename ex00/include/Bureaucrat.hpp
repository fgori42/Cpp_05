#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

class  Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &org);
	~ Bureaucrat();

	std::string	getName();
	int			getGrade();
	void		inmcrement();
	void		decrement();

	class GradeTooHighException : virtual std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : virtual std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	Bureaucrat &operator=(const Bureaucrat & org);
};

#endif