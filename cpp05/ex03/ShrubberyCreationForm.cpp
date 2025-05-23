/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 02:51:12 by soksak            #+#    #+#             */
/*   Updated: 2025/05/23 04:20:33 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), target("Default")
{
	std::cout << "Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "Parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy), target(copy.target)
{
	std::cout << "Copy constructor called" << std::endl;
}

ShrubberyCreationForm const &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->target = copy.target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::FormIsNotSignedException();
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();
	std::ofstream file((this->target + std::string("_shrubbery")).c_str());
	if (file.is_open())
	{
		file << "        *\n";
		file << "       /|\\\n";
		file << "      / | \\\n";
		file << "     /  |  \\\n";
		file << "    /   |   \\\n";
		file << "   /    |    \\\n";
		file << "  /     |     \\\n";
		file << " /______|______\\\n";
		file << "        |\n";
		file << "        |\n";
		file << "        |\n";
		file << "        |\n";
		file.close();
	}
	else
		throw ShrubberyCreationForm::FileOpenException();

}

const char* ShrubberyCreationForm::FileOpenException::what() const throw()
{
	return ("Error: File could not be opened");
}
