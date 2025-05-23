/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 06:07:44 by soksak            #+#    #+#             */
/*   Updated: 2025/05/22 08:06:28 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "<-- Constructors -->" << std::endl;
	Bureaucrat b1("John", 1);
	Bureaucrat b2("Jane", 150);
	Bureaucrat b3("Jack", 1);

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

	std::cout << "<-- Destructors -->" << std::endl;
	return (0);


}
