#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <exception>
# include "Bureaucrat.hpp"

class	Form
{
private:
	const std::string	_name;
	bool				_sign;
	const int			_gradeToSign;
	const int			_gradeToExe;
public:
	Form();
	Form(std::string name, int sign, int exe);
	Form(const Form &org);
	~Form();

	Form &operator=(const Form &org);

	void beSigned(Bureaucrat &buro);

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
};

std::ostream &operator<<(std::ostream &out, Form &form);

#endif