#include "Form.hpp"

Form::Form(): _name("default"), _sign(false), _gradeToSign(150), _gradeToExe(150)
{
	std::cout << "default costructor called" << std::endl;
}
Form::Form(std::string name, int sign, int exe): _name(name), _sign(false), _gradeToSign(sign), _gradeToExe(exe)
{
	std::cout << "costructor of form called name " << _name <<std::endl;
	if (_gradeToSign < 0 || _gradeToExe < 0)
		throw Form::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExe > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &org): _name(org._name), _sign(org._sign), _gradeToSign(org._gradeToSign), _gradeToExe(org._gradeToExe)
{
	std::cout << "cloning costructor called" << std::endl;
}
Form::~Form()
{
	std::cout << _name << "'s destructor called" << std::endl;
}

Form &Form::operator=(const Form &org)
{
	if (&org != this)
	{
		_sign = org._sign;
	}
	return (*this);
}

std::string	Form::getName()
{
	return _name;
}
bool	Form::getStatus()
{
	return _sign;
}
int	Form::getSignGrade()
{
	return _gradeToSign;
}
int	Form::getExeGrade()
{
	return _gradeToExe;
}

void Form::beSigned(Bureaucrat &buro)
{
	if (_sign == false)
	{
		if (buro.getGrade() <= _gradeToSign)
			_sign = true;
		else
			throw Form::GradeTooLowException();
	}
	else
		throw "form already signed";
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Error\nGrade too high for the form";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Error\nGrade too low for the form";
}

std::ostream &operator<<(std::ostream &out, Form &form)
{
	std::cout << "Form name:" << form.getName() << std::endl << "Form state:";
	if (form.getStatus())
		std::cout << "signed" << std::endl;
	else
		std::cout << "not signed" << std::endl;
	std::cout << "Form grade to be signed: " << form.getSignGrade() <<std::endl << "Form grade for execution: " << form.getExeGrade() << std::endl;
	return (out);
}