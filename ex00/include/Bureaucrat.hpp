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
	~Bureaucrat();

	std::string	getName();
	int			getGrade();
	void		increment();
	void		decrement();

	class GradeTooHighException : virtual std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return "Error\nGrade too high";
			}
	};

	class GradeTooLowException : virtual std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return "Error\nGrade too low";
			}
	};

	Bureaucrat &operator=(const Bureaucrat & org);
};



//const char	*Bureaucrat::GradeTooLowException::what() const throw()

#endif