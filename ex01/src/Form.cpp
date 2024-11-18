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

void Form::beSigned(Bureaucrat &buro)
{
	if (buro.getGrade() < _gradeToSign)
		_sign = true;
	else
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Error\nGrade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Error\nGrade too low";
}