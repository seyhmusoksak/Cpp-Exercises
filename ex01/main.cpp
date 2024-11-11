/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:50:10 by soksak            #+#    #+#             */
/*   Updated: 2024/11/12 01:50:27 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook phoneBook;
	std::string input;

	while (1)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, input);
		if (input == "EXIT")
			break;
		else if (input == "ADD")
			phoneBook.addContact();
		else if (input == "SEARCH")
			phoneBook.displayContacts();
	}
	return (0);
}
