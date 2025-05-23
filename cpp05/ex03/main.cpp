/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 06:07:44 by soksak            #+#    #+#             */
/*   Updated: 2025/05/23 05:13:19 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
	try
	{
		Intern someRandomIntern;

		std::cout << "<-- No Exception -->" << std::endl;
		AForm* rrf;
		AForm* rrf2;
		AForm* rrf3;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		rrf2 = someRandomIntern.makeForm("shrubbery creation", "Home");
		rrf3 = someRandomIntern.makeForm("presidential pardon", "President");
		delete rrf;
		delete rrf2;
		delete rrf3;

		std::cout << "<-- Exception -->" << std::endl;
		AForm* rrf4;
		rrf4 = someRandomIntern.makeForm("unknown form", "Unknown");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
