/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 04:27:24 by soksak            #+#    #+#             */
/*   Updated: 2025/05/23 05:11:56 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
}

Intern::Intern(Intern const &copy)
{
	*this = copy;
}

Intern const &Intern::operator=(Intern const &copy)
{
	(void)copy;
	return (*this);
}

Intern::~Intern(void)
{
}

void Intern::toLower(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = std::tolower(str[i]);
}
AForm *Intern::makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return ("Intern: Form not found");
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	if (formName.empty() || target.empty())
		throw FormNotFoundException();
	toLower(formName);
	fPointer levelPointer[3] = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			AForm *createdForm = (this->*levelPointer[i])(target);
			std::cout << "Intern creates " << *createdForm << std::endl;
			return (createdForm);
		}
	}
	throw FormNotFoundException();
}
