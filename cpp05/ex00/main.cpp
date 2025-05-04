/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 06:07:44 by soksak            #+#    #+#             */
/*   Updated: 2025/05/04 06:28:35 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "<-- Constructors -->" << std::endl;
	Bureaucrat b1("John", 1);

	std::cout << "<-- No Exception -->" << std::endl;
	try
	{
		std::cout << b1 << std::endl;
		b1.setGrade(50);
		std::cout << "Successfully changed grade of " << b1.getName() << std::endl;
		std::cout << b1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	std::cout << "<-- GradeTooHighException -->" << std::endl;

	try
	{
		std::cout << b1 << std::endl;
		b1.setGrade(0);
		std::cout << "Successfully changed grade of " << b1.getName() << std::endl;
		std::cout << b1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "<-- GradeTooLowException -->" << std::endl;
	try
	{
		std::cout << b1 << std::endl;
		b1.setGrade(151);
		std::cout << "Successfully changed grade of " << b1.getName() << std::endl;
		std::cout << b1 << std::endl;
	}

	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "<-- Destructors -->" << std::endl;
	return (0);


}
