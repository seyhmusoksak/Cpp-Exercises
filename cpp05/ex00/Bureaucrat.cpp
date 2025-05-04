/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 05:08:21 by soksak            #+#    #+#             */
/*   Updated: 2025/05/04 06:28:19 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(void) : name("Default"), grade(150)
{
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : name(name),  grade(150)
{
	std::cout << "Parameterized constructor called" << std::endl;
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : name(copy.name)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Bureaucrat const	&Bureaucrat::operator=(Bureaucrat const &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->grade = copy.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}
