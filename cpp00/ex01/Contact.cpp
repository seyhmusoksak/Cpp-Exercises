/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 00:59:34 by soksak            #+#    #+#             */
/*   Updated: 2024/11/26 02:52:32 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}
Contact::~Contact(void)
{
}

bool Contact::validateAlphabetic(const std::string &str) const
{
    for (size_t i = 0; i < str.length(); i++)
        if (!std::isalpha(str[i]))
            return false;
    return true;
}

bool Contact::validateNickname(const std::string &str) const
{
    bool hasSpace = false;
    bool hasContent = false;

    for (size_t i = 0; i < str.length(); i++) {
        if (std::isspace(str[i]))
            hasSpace = true;
        else if (std::isalnum(str[i]) || std::ispunct(str[i]))
            hasContent = true;
    }
    if (hasSpace && hasContent)
        return true;
    else if (!hasSpace && hasContent)
        return true;
    else
        return false;
}

bool Contact::validateDarkestSecret(const std::string &str) const
{
    bool hasSpace = false;
    bool hasContent = false;

    for (size_t i = 0; i < str.length(); i++) {
        if (std::isspace(str[i]))
            hasSpace = true;
        else if (std::isalnum(str[i]) || std::ispunct(str[i]))
            hasContent = true;
    }
    if (hasSpace && hasContent)
        return true;
    else if (!hasSpace && hasContent)
        return true;
    else
        return false;
}

bool Contact::validateNumeric(const std::string &str) const
{
    if (str.length() > 20 || str.length() < 7)
    {
        std::cout << "Phone number must be between 7 and 20 digits and include country code." << std::endl;
        return false;
    }
    for (size_t i = 0; i < str.length(); i++)
        if (!std::isdigit(str[i]))
        {
            std::cout << "Phone number must be numeric." << std::endl;
            return false;
        }
    return true;
}

int Contact::getInput(std::string &input, const std::string &prompt)
{
    std::cout << prompt;
    std::getline(std::cin, input);
    if (std::cin.eof())
        return -1;
    return input.empty() ? 0 : 1;
}

bool Contact::setFirstName(void)
{
    std::string input;
    int condition;

    while (true)
    {
        condition = getInput(input, "Enter first name: ");
        if (condition == -1)
            return false;
        else if (condition == 0)
        {
            std::cout << "The field can't be empty." << std::endl;
            continue;
        }
        if (!validateAlphabetic(input))
        {
            std::cout << "First name must be alphabetic." << std::endl;
            continue;
        }
        this->_firstName = input;
        return true;
    }
}

bool Contact::setLastName(void)
{
    std::string input;
    int condition;

    while (true)
    {
        condition = getInput(input, "Enter last name: ");
        if (condition == -1)
            return false;
        else if (condition == 0)
        {
            std::cout << "The field can't be empty." << std::endl;
            continue;
        }
        if (!validateAlphabetic(input))
        {
            std::cout << "Last name must be alphabetic." << std::endl;
            continue;
        }
        this->_lastName = input;
        return true;
    }
}

bool Contact::setNickName(void)
{
    std::string input;
    int condition;

    while (true)
    {
        condition = getInput(input, "Enter nickname: ");
        if (condition == -1)
            return false;
        else if (condition == 0)
        {
            std::cout << "The field can't be empty." << std::endl;
            continue;
        }
        if (!validateNickname(input))
        {
            std::cout << "Nickname must be something." << std::endl;
            continue;
        }
        this->_nickName = input;
        return true;
    }
}

bool Contact::setPhoneNumber(void)
{
    std::string input;
    int condition;

    while (true)
    {
        condition = getInput(input, "Enter phone number: ");
        if (condition == -1)
            return false;
        else if (condition == 0)
        {
            std::cout << "The field can't be empty." << std::endl;
            continue;
        }
        if (!validateNumeric(input))
            continue;
        this->_phoneNumber = input;
        return true;
    }
}

bool Contact::setDarkestSecret(void)
{
    std::string input;
    int condition;
    while (true)
    {
        condition = getInput(input, "Enter darkest secret: ");
        if (condition == -1)
            return false;
        else if (condition == 0)
        {
            std::cout << "The field can't be empty." << std::endl;
            continue;
        }
        if (!validateDarkestSecret(input))
        {
            std::cout << "Darkest secret must contain something." << std::endl;
            continue;
        }
        this->_darkestSecret = input;
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
