/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:39:39 by soksak            #+#    #+#             */
/*   Updated: 2025/01/15 06:18:19 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap Gwen("Gwen");
	ClapTrap Zed("Zed");

	Gwen.showStatus("ScavTrap");
	Zed.showStatus("ClapTrap");

	Gwen.attack(Zed.getName());
	Zed.takeDamage(Gwen.getAttackDamage());
	Zed.showStatus("ClapTrap");

	Zed.beRepaired(0);
	Zed.showStatus("ClapTrap");
	Zed.attack(Gwen.getName());

	Gwen.guardGate();
}
