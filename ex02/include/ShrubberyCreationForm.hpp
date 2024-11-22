#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &org);
	~ShrubberyCreationForm();

	void	execute(Bureaucrat const & executor) const;

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &org);
};

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137)
{
	_target = target;
	std::cout << "ShrubberyCreationForm costructor called target: " << _target << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm default costructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &org): AForm("ShrubberyCreationForm", 145, 137)
{
	_target = org._target;
	std::cout << "ShrubberyCreationForm clone costructor called target: " << _target << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &org)
{
	if (this != &org)
		_target = org._target;
	std::cout << "ShrubberyCreationForm operator called new target: " << _target << std::endl;
	return(*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getStatus())
		throw AForm::IsnSignedForm();
	if (this->getExeGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();
	std::ofstream 	tree;
	std::string		newfile = _taget + "_shrubbery";
	tree.open(newfile, c_str());
	tree << "   /|\
    /*|O\
   /*/|\*\
  /X/O|*\X\
 /*/X/|\X\*\
/O/*/X|O\X\*\
      |||
      |||
      |||" << std::endl;

}

#endif