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

#endif