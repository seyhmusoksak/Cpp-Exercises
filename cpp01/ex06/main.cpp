/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 05:04:27 by soksak            #+#    #+#             */
/*   Updated: 2025/01/10 22:03:40 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		Harl gwen;
		int caseLevel;

		std::string level = argv[1];
		caseLevel = getLevelNumber(level);
		switch (caseLevel)
		{
			case 0:
				gwen.complain("DEBUG");
				std::cout << std::endl;
			case 1:
				gwen.complain("INFO");
				std::cout << std::endl;
			case 2:
				gwen.complain("WARNING");
				std::cout << std::endl;
			case 3:
				gwen.complain("ERROR");
				std::cout << std::endl;
				break;
			default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		}
		return (1);
	}
	std::cout << "Usage: ./harlfilter [message]" << std::endl;
	return (0);

}
