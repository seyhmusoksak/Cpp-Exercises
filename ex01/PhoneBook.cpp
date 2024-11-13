/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:02:21 by soksak            #+#    #+#             */
/*   Updated: 2024/11/13 11:37:37 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_nbContacts = 0;
	this->_oldIndex = 0;
}

void	PhoneBook::firstNameField(Contact& contact)
{
	std::string input;

	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "The field can't be empty." << std::endl;
		firstNameField(contact);
		return ;
	}
	for(size_t i; i < input.length(); i++)
	{
		if (!std::isalpha(input[i]))
		{
			std::cout << "First name must be alphabetic." << std::endl;
			lastNameField(contact);
			return ;
		}
	}
	contact.setFirstName(input);
}

void	PhoneBook::lastNameField(Contact& contact)
{
	std::string input;

	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "The field can't be empty." << std::endl;
		lastNameField(contact);
		return ;
	}
	for(size_t i; i < input.length(); i++)
	{
		if (!std::isalpha(input[i]))
		{
			std::cout << "Last name must be alphabetic." << std::endl;
			lastNameField(contact);
			return ;
		}
	}
	contact.setLastName(input);
}

void	PhoneBook::nickNameField(Contact& contact)
{
	std::string input;

	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "The field can't be empty." << std::endl;
		nickNameField(contact);
		return ;
	}
	for(size_t i; i < input.length(); i++)
	{
		if (!std::isalpha(input[i]) || !std::isdigit(input[i]))
		{
			std::cout << "You can't use whitespace characters!" << std::endl;
			lastNameField(contact);
			return ;
		}
	}
	contact.setNickName(input);
}


void	PhoneBook::phoneNumberField(Contact& contact)
{
	std::string input;

	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "The field can't be empty." << std::endl;
		phoneNumberField(contact);
		return ;
	}
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!std::isdigit(input[i]))
		{
			std::cout << "Phone number must be digits." << std::endl;
			phoneNumberField(contact);
			return	;
		}
	}
	contact.setPhoneNumber(input);
}

void PhoneBook::darkestSecretField(Contact& contact)
{
	std::string input;

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "The field can't be empty." << std::endl;
		darkestSecretField(contact);
	}
	else
		contact.setDarkestSecret(input);
}


void PhoneBook::addContact(void)
{
	Contact contact;
	std::string input;

	firstNameField(contact);
	lastNameField(contact);
	nickNameField(contact);
	phoneNumberField(contact);
	darkestSecretField(contact);
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
	int i = 0;
	std::string input;

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	while (i < this->_nbContacts)
	{
		std::cout << "|" << std::setw(10) << i << "|";
		if (this->_contacts[i].getFirstName().length() > 10)
			std::cout << std::setw(10) << this->_contacts[i].getFirstName().substr(0, 9) + "." << "|";
		else
			std::cout << std::setw(10) << this->_contacts[i].getFirstName() << "|";
		if (this->_contacts[i].getLastName().length() > 10)
			std::cout << std::setw(10) << this->_contacts[i].getLastName().substr(0, 9) + "." << "|";
		else
			std::cout << std::setw(10) << this->_contacts[i].getLastName() << "|";
		if (this->_contacts[i].getNickName().length() > 10)
			std::cout << std::setw(10) << this->_contacts[i].getNickName().substr(0, 9) + "." << "|";
		else
			std::cout << std::setw(10) << this->_contacts[i].getNickName() << "|";
		std::cout << std::endl << "---------------------------------------------" << std::endl;
		i++;
	}
	std::cout << "Enter index: ";
	std::getline(std::cin, input);
	std::stringstream ss(input);
	ss >> i;
	searchContact(i);
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


