/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:39:39 by soksak            #+#    #+#             */
/*   Updated: 2025/01/15 06:21:39 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap gwen("Gwen");
	ClapTrap zed("Zed");

	gwen.showStatus("ScavTrap");
	zed.showStatus("ClapTrap");

	gwen.attack(zed.getName());
	zed.takeDamage(gwen.getAttackDamage());
	zed.showStatus("ClapTrap");

	zed.beRepaired(0);
	zed.showStatus("ClapTrap");
	zed.attack(gwen.getName());

	gwen.guardGate();
}
