/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:02:21 by soksak            #+#    #+#             */
/*   Updated: 2024/11/12 01:50:00 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_nbContacts = 0;
	this->_oldIndex = 0;
}

void PhoneBook::addContact(void)
{
	Contact contact;
	std::string input;


	std::cout << "First name: ";
	std::getline(std::cin, input);
	contact.setFirstName(input);
	std::cout << "Last name: ";
	std::getline(std::cin, input);
	contact.setLastName(input);
	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	contact.setNickName(input);
	std::cout << "Phone number: ";
	std::getline(std::cin, input);
	contact.setPhoneNumber(input);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, input);
	contact.setDarkestSecret(input);
	if (this->_nbContacts < 8)
	{
		this->_contacts[this->_nbContacts] = contact;
		this->_nbContacts++;
	}
	else
	{
		this->_contacts[_oldIndex] = contact;
        _oldIndex = (_oldIndex + 1) % 8;
	}
}

void PhoneBook::displayContacts(void)
{
	int i;
	int j;

	i = 0;
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	while (i < this->_nbContacts)
	{
		std::cout << "         " << i << "|";
		j = 0;
		while (j < 3)
		{
			if (this->_contacts[i].getFirstName().length() > 10)
				std::cout << this->_contacts[i].getFirstName().substr(0, 9) << ".";
			else
				std::cout << this->_contacts[i].getFirstName();
			if (j == 0)
				std::cout << "|";
			else if (j == 1)
				std::cout << "|";
			else
				std::cout << std::endl;
			j++;
		}
		i++;
	}
}


void PhoneBook::searchContact(int index)
{
	if (index < this->_nbContacts)
	{
		std::cout << "First name: " << this->_contacts[index].getFirstName() << std::endl;
		std::cout << "Last name: " << this->_contacts[index].getLastName() << std::endl;
		std::cout << "Nickname: " << this->_contacts[index].getNickName() << std::endl;
		std::cout << "Phone number: " << this->_contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest secret: " << this->_contacts[index].getDarkestSecret() << std::endl;
	}
	else
		std::cout << "Invalid index" << std::endl;
}


