/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 06:07:44 by soksak            #+#    #+#             */
/*   Updated: 2025/05/22 08:08:27 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "<-- Constructors -->" << std::endl;
	Bureaucrat b1("John", 1);
	Bureaucrat b2("Jane", 150);
	Bureaucrat b3("Jack", 1);

	// Form Tests
	Form f1("Form1", 50, 50);
	Form f2("Form2", 50, 50);
	Bureaucrat b4("Bureaucrat1", 50);

	std::cout << "<-- No Exception -->" << std::endl;
	try
	{
		std::cout << b1;
		b1.decrementGrade();
		std::cout << "Successfully changed grade of " << b1.getName() << std::endl;
		std::cout << b1;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	std::cout << "<-- GradeTooLowException -->" << std::endl;

	try
	{
		std::cout << b2;
		b2.decrementGrade();
		std::cout << "Successfully changed grade of " << b2.getName() << std::endl;
		std::cout << b2;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "<-- GradeTooHighException -->" << std::endl;
	try
	{
		std::cout << b3;
		b3.incrementGrade();
		std::cout << "Successfully changed grade of " << b3.getName() << std::endl;
		std::cout << b3;
	}

	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "<-- Tests With Form -->" << std::endl;

	std::cout << f1;
	std::cout << b4;

	std::cout << "<-- Form No Exception -->" << std::endl;
	b4.signForm(f1);
	std::cout << f1;

	std::cout << "<-- Signing Form Again -->" << std::endl;
	b4.signForm(f1);

	std::cout << "<-- Form GradeTooLowException -->" << std::endl;
	b4.decrementGrade();
	b4.signForm(f2);


	std::cout << "<-- Destructors -->" << std::endl;
	return (0);


}
