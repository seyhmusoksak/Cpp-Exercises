/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 06:07:44 by soksak            #+#    #+#             */
/*   Updated: 2025/05/23 04:17:25 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	try
	{

		std::cout << "<-- Constructors -->" << std::endl;
		// Bureaucrats
		Bureaucrat Bob("Bob", 1);
		Bureaucrat John("John", 75);
		Bureaucrat Jack("Jack", 4);
		Bureaucrat Emily("Emily", 150);

		// Forms
		ShrubberyCreationForm Shrubbery("Home");
		RobotomyRequestForm Robotomy("Robot");
		PresidentialPardonForm Presidential("President");

		std::cout << "<-- No Exception -->" << std::endl;
		std::cout << Bob;
		Bob.signForm(Shrubbery);
		Bob.executeForm(Shrubbery);
		std::cout << Shrubbery;
		Bob.signForm(Robotomy);
		Bob.executeForm(Robotomy);
		std::cout << Robotomy;
		Bob.signForm(Presidential);
		Bob.executeForm(Presidential);
		std::cout << Presidential;
		std::cout << "<-- With Exception -->" << std::endl;

		// Grade Already Signed
		std::cout << John;
		John.signForm(Robotomy);

		// Grade is too low
		John.executeForm(Robotomy);

		std::cout << "<-- Some Tests Again -->" << std::endl;

		// Already Signed
		Emily.signForm(Presidential);

		// Grade is too low
		Emily.executeForm(Presidential);

		// Execution Success
		Jack.executeForm(Presidential);
		John.executeForm(Shrubbery);

		// Execution %50 chance.
		Jack.executeForm(Robotomy);

		std::cout << "<-- Destructors -->" << std::endl;

		// Exception Caught
		Emily.decrementGrade();

	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
