/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:40:17 by soksak            #+#    #+#             */
/*   Updated: 2025/01/15 03:45:15 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("default"), hitPts(10), energyPts(10), attackDamage(0)
{
	std::cout << "Default constructor called";
}

ClapTrap::ClapTrap(std::string& n): name(n), hitPts(10), energyPts(10), attackDamage(0)
{
	std::cout << "String constructor called";
}

ClapTrap::ClapTrap(ClapTrap& t)
{
	std::cout << "Copy constructor called";
	*this = t;
}

ClapTrap& ClapTrap::operator=(ClapTrap &other)
{
	std::cout << "Copy Assignment operator called";
	this->name = other.name;
	this->hitPts = other.hitPts;
	this->energyPts = other.energyPts;
	this->attackDamage = other.attackDamage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called";
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->energyPts > 0 && this->hitPts > 0)
	{
		this->energyPts -= 1;
		this->hitPts -= 1;
		std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->attackDamage << " points of damage!";
	}
	else if (this->energyPts == 0)
		std::cout << "ClapTrap " << this->name << " has no energy points left to attack!";
	else
		std::cout << "ClapTrap " << this->name << " has no hit points left to attack!";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPts > 0 && this->hitPts > 0)
	{
		this->energyPts -= 1;
		this->hitPts += amount;
		std::cout << "ClapTrap " << this->name << " is repaired for " << amount << " points!";
	}
	else if (this->energyPts == 0)
		std::cout << "ClapTrap " << this->name << " has no energy points left to repair!";
	else
		std::cout << "ClapTrap " << this->name << " has no hit points left to repair!";
}
