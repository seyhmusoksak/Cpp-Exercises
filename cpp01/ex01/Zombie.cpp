/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 04:51:02 by soksak            #+#    #+#             */
/*   Updated: 2024/11/19 04:53:05 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::~Zombie()
{
	std::cout << this->zombieName << " has been destroyed." << std::endl;
}

Zombie::Zombie()
{
	this->zombieName = "Zombie";
}

Zombie::Zombie( std::string zombieName )
{
	this->zombieName = zombieName;
}

void Zombie::setName( std::string name )
{
	this->zombieName = name;
	return;
}

void Zombie::announce( void )
{
	std::cout << this->zombieName << ":" << " BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}


