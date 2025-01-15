/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:40:17 by soksak            #+#    #+#             */
/*   Updated: 2025/01/15 06:29:01 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("Default"), hitPts(10), energyPts(10), attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& n): name(n), hitPts(10), energyPts(10), attackDamage(0)
{
	std::cout << "ClapTrap String constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& t)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = t;
}

ClapTrap& ClapTrap::operator=(ClapTrap &other)
{
	std::cout << "ClapTrap Copy Assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	this->name = other.name;
	this->hitPts = other.hitPts;
	this->energyPts = other.energyPts;
	this->attackDamage = other.attackDamage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->energyPts > 0 && this->hitPts > 0)
	{
		this->energyPts -= 1;
		std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
	}
	else if (this->energyPts == 0)
		std::cout << "ClapTrap " << this->name << " has no energy points left to attack!" << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " has no hit points left to attack!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPts >= amount)
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
	if (this->energyPts > 0 && this->hitPts > 0 && amount > 0)
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

void	ClapTrap::showStatus(std::string const &className)
{
	std::cout << className << " " << this->name << " has " << this->hitPts << " hit points, " << this->energyPts << " energy points." << std::endl;
}

std::string ClapTrap::getName() const
{
	return (this->name);
}

unsigned int ClapTrap::getHitPts() const
{
	return (this->hitPts);
}

unsigned int ClapTrap::getEnergyPts() const
{
	return (this->energyPts);
}

unsigned int ClapTrap::getAttackDamage() const
{
	return (this->attackDamage);
}
