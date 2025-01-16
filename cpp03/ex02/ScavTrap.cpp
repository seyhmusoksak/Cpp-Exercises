/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 04:57:39 by soksak            #+#    #+#             */
/*   Updated: 2025/01/16 10:31:26 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	this->hitPts = 100;
	this->energyPts = 50;
	this->attackDamage = 20;
	this->guardMode = false;
}

ScavTrap::ScavTrap(const std::string& n): ClapTrap(n)
{
	std::cout << "ScavTrap String constructor called" << std::endl;
	this->hitPts = 100;
	this->energyPts = 50;
	this->attackDamage = 20;
	this->guardMode = false;
}

ScavTrap::ScavTrap(ScavTrap& t) : ClapTrap(t)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap &other)
{
	std::cout << "ScavTrap Copy Assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	this->name = other.name;
	this->hitPts = other.hitPts;
	this->energyPts = other.energyPts;
	this->attackDamage = other.attackDamage;
	this->guardMode = other.guardMode;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->guardMode == false)
	{
		std::cout << "ScavTrap " << this->name << " has entered in Gate keeper mode!" << std::endl;
		this->guardMode = true;
	}
	else
		std::cout << "ScavTrap " << this->name << " is already in Gate keeper mode!" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->energyPts > 0 && this->hitPts > 0)
	{
		this->energyPts -= 1;
		std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
	}
	else if (this->energyPts == 0)
		std::cout << "ScavTrap " << this->name << " has no energy points left to attack!" << std::endl;
	else
		std::cout << "ScavTrap " << this->name << " has no hit points left to attack!" << std::endl;
}
