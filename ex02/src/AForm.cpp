#include "AForm.hpp"

AForm::AForm(): _name("default"), _sign(false), _gradeToSign(150), _gradeToExe(150)
{
	std::cout << "default costructor called" << std::endl;
}
AForm::AForm(std::string name, int sign, int exe): _name(name), _sign(false), _gradeToSign(sign), _gradeToExe(exe)
{
	std::cout << "costructor of form called name " << _name <<std::endl;
	if (_gradeToSign < 0 || _gradeToExe < 0)
		throw AForm::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExe > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &org): _name(org._name), _sign(org._sign), _gradeToSign(org._gradeToSign), _gradeToExe(org._gradeToExe)
{
	std::cout << "cloning costructor called" << std::endl;
}
AForm::~AForm()
{
	std::cout << _name << "'s destructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &org)
{
	if (&org != this)
	{
		_sign = org._sign;
	}
	return (*this);
}

std::string	AForm::getName()
{
	return _name;
}
bool	AForm::getStatus()
{
	return _sign;
}
int	AForm::getSignGrade()
{
	return _gradeToSign;
}
int	AForm::getExeGrade()
{
	return _gradeToExe;
}

void AForm::beSigned(Bureaucrat &buro)
{
	if (_sign == false)
	{
		if (buro.getGrade() <= _gradeToSign)
			_sign = true;
		else
			throw AForm::GradeTooLowException();
	}
	else
		throw AForm::IsSignedForm();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Error:: Grade too high for the form";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Error:: Grade too low for the form";
}

const char *AForm::IsSignedForm::what() const throw()
{
	return "the form is already signed";
}

std::ostream &operator<<(std::ostream &out, AForm &form)
{
	std::cout << "Form name:" << form.getName() << std::endl << "Form state:";
	if (form.getStatus())
		std::cout << "signed" << std::endl;
	else
		std::cout << "not signed" << std::endl;
	std::cout << "Form grade to be signed: " << form.getSignGrade() <<std::endl << "Form grade for execution: " << form.getExeGrade() << std::endl;
	return (out);
}