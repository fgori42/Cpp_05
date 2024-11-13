#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

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

	Bureaucrat &operator=(const Bureaucrat & org);
};

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
}

Bureaucrat::~ Bureaucrat()
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

void		Bureaucrat::inmcrement()
{
	_grade -= 1;
}
void		Bureaucrat::decrement()
{
	_grade += 1;
}

#endif