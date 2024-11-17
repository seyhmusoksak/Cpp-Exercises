/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 00:59:34 by soksak            #+#    #+#             */
/*   Updated: 2024/11/13 11:54:19 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

bool Contact::validateAlphabetic(const std::string &str) const
{
    for (size_t i = 0; i < str.length(); i++)
        if (!std::isalpha(str[i]))
            return false;
    return true;
}

bool Contact::validateAlphanumeric(const std::string &str) const
{
    for (size_t i = 0; i < str.length(); i++)
        if (!std::isalnum(str[i]))
            return false;
    return true;
}

bool Contact::validateNumeric(const std::string &str) const
{
    for (size_t i = 0; i < str.length(); i++)
        if (!std::isdigit(str[i]))
            return false;
    return true;
}

bool Contact::getInput(std::string &input, const std::string &prompt)
{
    std::cout << prompt;
    std::getline(std::cin, input);
    return !input.empty();
}

bool Contact::setFirstName(void)
{
    std::string input;
    while (true)
    {
        if (!getInput(input, "Enter first name: "))
        {
            std::cout << "The field can't be empty." << std::endl;
            continue;
        }
        if (!validateAlphabetic(input))
        {
            std::cout << "First name must be alphabetic." << std::endl;
            continue;
        }
        _firstName = input;
        return true;
    }
}

bool Contact::setLastName(void)
{
    std::string input;
    while (true)
    {
        if (!getInput(input, "Enter last name: "))
        {
            std::cout << "The field can't be empty." << std::endl;
            continue;
        }
        if (!validateAlphabetic(input))
        {
            std::cout << "Last name must be alphabetic." << std::endl;
            continue;
        }
        _lastName = input;
        return true;
    }
}

bool Contact::setNickName(void)
{
    std::string input;
    while (true)
    {
        if (!getInput(input, "Enter nickname: "))
        {
            std::cout << "The field can't be empty." << std::endl;
            continue;
        }
        if (!validateAlphanumeric(input))
        {
            std::cout << "Nickname must be alphanumeric." << std::endl;
            continue;
        }
        _nickName = input;
        return true;
    }
}

bool Contact::setPhoneNumber(void)
{
    std::string input;
    while (true)
    {
        if (!getInput(input, "Enter phone number: "))
        {
            std::cout << "The field can't be empty." << std::endl;
            continue;
        }
        if (!validateNumeric(input))
        {
            std::cout << "Phone number must be numeric." << std::endl;
            continue;
        }
        _phoneNumber = input;
        return true;
    }
}

bool Contact::setDarkestSecret(void)
{
    std::string input;
    while (true)
    {
        if (!getInput(input, "Enter darkest secret: "))
        {
            std::cout << "The field can't be empty." << std::endl;
            continue;
        }
        _darkestSecret = input;
        return true;
    }
}

std::string Contact::getFirstName(void) const
{
	return (this->_firstName);
}

std::string Contact::getLastName(void) const
{
	return (this->_lastName);
}

std::string Contact::getNickName(void) const
{
	return (this->_nickName);
}

std::string Contact::getPhoneNumber(void) const
{
	return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret(void) const
{
	return (this->_darkestSecret);
}
