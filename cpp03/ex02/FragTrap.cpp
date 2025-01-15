/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FrapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:49:47 by soksak            #+#    #+#             */
/*   Updated: 2025/01/15 08:59:39 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


FragTrap::FragTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	this->hitPts = 100;
	this->energyPts = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const std::string& n): ClapTrap(n)
{
	std::cout << "FragTrap String constructor called" << std::endl;
	this->hitPts = 100;
	this->energyPts = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(FragTrap& t) : ClapTrap(t)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap &other)
{
	std::cout << "FragTrap Copy Assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	this->name = other.name;
	this->hitPts = other.hitPts;
	this->energyPts = other.energyPts;
	this->attackDamage = other.attackDamage;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " requests a high five! " << std::endl;
}
