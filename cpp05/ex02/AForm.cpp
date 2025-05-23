/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 03:15:09 by soksak            #+#    #+#             */
/*   Updated: 2025/05/23 00:17:39 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : name("Default"), isSigned(false), signGrade(150), executeGrade(150)
{
	std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(const std::string name, const int signGrade, const int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	std::cout << "Parameterized constructor called" << std::endl;
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &copy) : name(copy.name), isSigned(copy.isSigned), signGrade(copy.signGrade), executeGrade(copy.executeGrade)
{
	std::cout << "Copy constructor called" << std::endl;
}

AForm const	&AForm::operator=(AForm const &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->isSigned = copy.isSigned;
	return (*this);
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->signGrade)
		this->isSigned = true;
	else
		throw GradeTooLowException();
}

AForm::~AForm(void)
{
	std::cout << "Destructor called" << std::endl;
}

std::string AForm::getName() const
{
	return (this->name);
}

bool AForm::getIsSigned() const
{
	return (this->isSigned);
}


int AForm::getSignGrade() const
{
	return (this->signGrade);
}


int AForm::getExecuteGrade() const
{
	return (this->executeGrade);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* AForm::FormIsNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

std::ostream &operator<<(std::ostream &os,  AForm const &form)
{
	os << "Name: " << form.getName() << " isSigned: " << form.getIsSigned() << " signGrade: " << form.getSignGrade() << " executeGrade: " << form.getExecuteGrade() << std::endl;
	return (os);
}

