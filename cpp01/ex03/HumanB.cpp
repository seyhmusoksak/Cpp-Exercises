/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 02:00:08 by soksak            #+#    #+#             */
/*   Updated: 2025/01/12 00:36:19 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : humanName(name), weapon(NULL)
{
}

HumanB::~HumanB(void)
{
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack(void)
{
	if (!this->weapon)
	{
		std::cout << this->humanName << " has no weapon to attack." << std::endl;
		return ;
	}
	std::cout << this->humanName << " attacks with his " << this->weapon->getType() << std::endl;
}
