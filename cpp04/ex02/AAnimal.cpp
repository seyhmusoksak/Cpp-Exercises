/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 05:51:11 by soksak            #+#    #+#             */
/*   Updated: 2025/01/17 09:06:18 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal default constructor called" << std::endl;
	this->type = "AAnimal";
}

AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = copy;
}

AAnimal &AAnimal::operator=(const AAnimal &copy)
{
	std::cout << "AAnimal assignation operator called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

void AAnimal::makeSound() const
{
	std::cout << "Default AAnimal Sound" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
	return (this->type);
}




