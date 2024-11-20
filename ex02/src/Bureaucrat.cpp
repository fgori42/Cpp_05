#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150)
{
	std::cout << "default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &org): _name(org._name), _grade(org._grade)
{
	std::cout << "clone constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat & org)
{
	if (this != &org)
	{
		_grade = org._grade;
	}
	std::cout << "clone operator called" << std::endl;
	return (*this);
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	std::cout << "constructor called: Bureaucrat named " << _name << std::endl;
	if (grade > 150){
		throw Bureaucrat::GradeTooLowException();
		}
	if (grade < 1){
		throw Bureaucrat::GradeTooHighException();
		}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}


std::string	Bureaucrat::getName()
{
	return _name;
}

int	Bureaucrat::getGrade()
{
	return _grade;
}

void		Bureaucrat::increment()
{
	if (_grade - 1 < 1){
		throw Bureaucrat::GradeTooHighException();
	}
	_grade -= 1;
}
void		Bureaucrat::decrement()
{
	if (_grade + 1 > 150){
		throw Bureaucrat::GradeTooLowException();
	}
	_grade += 1;
}
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Error\nGrade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Error\nGrade too low";
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &error)
	{
		std::cerr << _name << " couldn’t sign " << form.getName() << " because " <<error.what() << std::endl;
	}

}

std::ostream &operator<<(std::ostream &out, Bureaucrat &buro)
{
	std::cout << buro.getName() << ", bureaucrat grade " << buro.getGrade() << std::endl;
	return(out);
}
