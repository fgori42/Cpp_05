#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class	AForm
{
private:
	const std::string	_name;
	bool				_sign;
	const int			_gradeToSign;
	const int			_gradeToExe;
public:
	AForm();
	AForm(std::string name, int sign, int exe);
	AForm(const AForm &org);
	virtual ~AForm();

	AForm &operator=(const AForm &org);

	std::string	getName() const;
	bool		getStatus() const;
	int			getSignGrade() const;
	int			getExeGrade() const;
	
	virtual void		execute(Bureaucrat const & executor) const = 0;

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

	class IsSignedForm : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class IsnSignedForm : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, AForm &form);

#endif