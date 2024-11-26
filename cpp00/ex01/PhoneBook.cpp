/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:02:21 by soksak            #+#    #+#             */
/*   Updated: 2024/11/26 02:55:01 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_nbContacts = 0;
	this->_oldIndex = 0;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "See you again.." << std::endl;
}
int PhoneBook::addContact(void)
{
    Contact contact;

    if (!contact.setFirstName() ||
        !contact.setLastName() ||
        !contact.setNickName() ||
        !contact.setPhoneNumber() ||
        !contact.setDarkestSecret())
        return -1;

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
	return 0;
}

void PhoneBook::displayContacts(void)
{
	int i = 1;

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	while (i <= this->_nbContacts)
	{
		std::cout << "|" << std::setw(10) << i << "|";
		if (this->_contacts[i - 1].getFirstName().length() > 10)
			std::cout << std::setw(10) << this->_contacts[i - 1].getFirstName().substr(0, 9) + "." << "|";
		else
			std::cout << std::setw(10) << this->_contacts[i - 1].getFirstName() << "|";
		if (this->_contacts[i - 1].getLastName().length() > 10)
			std::cout << std::setw(10) << this->_contacts[i - 1].getLastName().substr(0, 9) + "." << "|";
		else
			std::cout << std::setw(10) << this->_contacts[i - 1].getLastName() << "|";
		if (this->_contacts[i - 1].getNickName().length() > 10)
			std::cout << std::setw(10) << this->_contacts[i - 1].getNickName().substr(0, 9) + "." << "|";
		else
			std::cout << std::setw(10) << this->_contacts[i - 1].getNickName() << "|";
		std::cout << std::endl << "---------------------------------------------" << std::endl;
		i++;
	}
}

int	PhoneBook::getContactIndex(void)
{
	std::string input;
	int index;

	while (1)
	{
		std::cout << "Enter the index of the contact: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (-1);
		else if (!input.empty())
		{
			if (input.length() == 1 && std::isdigit(input[0]))
			{
				index = input[0] - '0';
				if (index > 0 && index <= this->_nbContacts)
					return (index);
				else
					std::cout << "Invalid index" << std::endl;
			}
			else {
				std::cout << "Invalid index" << std::endl;
			}
		}
		else {
			std::cout << "The field can't be empty." << std::endl;
		}
	}


}

int PhoneBook::searchContact(void)
{
	int index;

	if (this->_nbContacts == 0)
	{
		std::cout << "No contacts available." << std::endl;
		return 1;
	}
	this->displayContacts();
	index = this->getContactIndex();
	if (index == -1)
		return (-1);
	std::cout << "First name: " << this->_contacts[index - 1].getFirstName() << std::endl;
	std::cout << "Last name: " << this->_contacts[index - 1].getLastName() << std::endl;
	std::cout << "Nickname: " << this->_contacts[index - 1].getNickName() << std::endl;
	std::cout << "Phone number: " << this->_contacts[index - 1].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->_contacts[index - 1].getDarkestSecret() << std::endl;
	return 0;
}


