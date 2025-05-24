/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 00:23:05 by soksak            #+#    #+#             */
/*   Updated: 2025/05/24 16:40:27 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), target("Default")
{
	std::cout << "Default constructor called" << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << "Parameterized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy), target(copy.target)
{
	std::cout << "Copy constructor called" << std::endl;
}

RobotomyRequestForm const &RobotomyRequestForm::operator=(RobotomyRequestForm const &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->target = copy.target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Destructor called" << std::endl;
}


void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::FormIsNotSignedException();
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();
	std::cout << "*** Some drilling noises ***" << std::endl;
	srand(time(0));
	if (rand() % 2 == 0)
		std::cout << this->target << " has been robotomized successfully!" << std::endl;
	else
		throw RobotomyRequestForm::RobotomyFailedException();
}


const char* RobotomyRequestForm::RobotomyFailedException::what() const throw()
{
	return ("Robotomy failed");
}

