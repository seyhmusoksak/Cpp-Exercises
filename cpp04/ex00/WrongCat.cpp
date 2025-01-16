/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 07:09:46 by soksak            #+#    #+#             */
/*   Updated: 2025/01/17 00:23:28 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}


WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	std::cout << "WrongCat assignation operator called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat sound: Meow Meow" << std::endl;
}


WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

std::string WrongCat::getType() const
{
	return (this->type);
}
