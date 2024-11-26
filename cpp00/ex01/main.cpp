/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:50:10 by soksak            #+#    #+#             */
/*   Updated: 2024/11/26 02:47:33 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook phoneBook;
	std::string input;

	std::cout << "-------80s PhoneBook-------" << std::endl;
	std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;
	while (1)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "EOF received, exitting." << std::endl;
			break;
		}
		else if (input == "EXIT")
			break;
		else if (input == "ADD")
		{
			if (phoneBook.addContact() == -1)
			{
				std::cout << "EOF received, exitting." << std::endl;
				break;
			}
		}
		else if (input == "SEARCH")
		{
			if (phoneBook.searchContact() == -1)
			{
				std::cout << "EOF received, exitting." << std::endl;
				break;
			}
		}
		else
			std::cout << "Invalid command." << std::endl;
	}
	return (0);
}
