/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 03:15:09 by soksak            #+#    #+#             */
/*   Updated: 2025/05/21 19:43:52 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : name("Default"), isSigned(false), signGrade(150), executeGrade(150)
{
	std::cout << "Default constructor called" << std::endl;
}

Form::Form(const std::string name, const int signGrade, const int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	std::cout << "Parameterized constructor called" << std::endl;
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &copy) : name(copy.name), isSigned(copy.isSigned), signGrade(copy.signGrade), executeGrade(copy.executeGrade)
{
	std::cout << "Copy constructor called" << std::endl;
}

Form const	&Form::operator=(Form const &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->isSigned = copy.isSigned;
	return (*this);
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->signGrade)
		this->isSigned = true;
	else
		throw GradeTooLowException();
}

Form::~Form(void)
{
	std::cout << "Destructor called" << std::endl;
}

std::string Form::getName() const
{
	return (this->name);
}

bool Form::getIsSigned() const
{
	return (this->isSigned);
}


int Form::getSignGrade() const
{
	return (this->signGrade);
}


int Form::getExecuteGrade() const
{
	return (this->executeGrade);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}


std::ostream &operator<<(std::ostream &os,  Form const &form)
{
	os << "Name: " << form.getName() << " isSigned: " << form.getIsSigned() << " signGrade: " << form.getSignGrade() << " executeGrade: " << form.getExecuteGrade() << std::endl;
	return (os);
}

