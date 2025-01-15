/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:40:17 by soksak            #+#    #+#             */
/*   Updated: 2025/01/15 04:22:11 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("Default"), hitPts(10), energyPts(10), attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& n): name(n), hitPts(10), energyPts(10), attackDamage(0)
{
	std::cout << "String constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& t)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = t;
}

ClapTrap& ClapTrap::operator=(ClapTrap &other)
{
	std::cout << "Copy Assignment operator called" << std::endl;
	this->name = other.name;
	this->hitPts = other.hitPts;
	this->energyPts = other.energyPts;
	this->attackDamage = other.attackDamage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->energyPts > 0 && this->hitPts > 0)
	{
		this->energyPts -= 1;
		this->hitPts -= 1;
		std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
	}
	else if (this->energyPts == 0)
		std::cout << "ClapTrap " << this->name << " has no energy points left to attack!" << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " has no hit points left to attack!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPts >= (int)amount)
		this->hitPts -= amount;
	else if (this->hitPts > 0)
		this->hitPts = 0;
	else
	{
		std::cout << "ClapTrap " << this->name << " is already dead!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage! now has " << this->hitPts << " hit points!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPts > 0 && this->hitPts > 0 && (this->hitPts + amount) <= 10)
	{
		this->energyPts -= 1;
		this->hitPts += amount;
		std::cout << "ClapTrap " << this->name << " is repaired for " << amount << " points!" << std::endl;
	}
	else if (this->energyPts == 0)
		std::cout << "ClapTrap " << this->name << " has no energy points left to repair!" << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " has no hit points left to repair!" << std::endl;
}
