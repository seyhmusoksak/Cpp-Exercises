/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:39:39 by soksak            #+#    #+#             */
/*   Updated: 2025/01/16 04:48:41 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ClapTrap gwen("Gwen");
	ScavTrap zed("Zed");

	std::cout << "=======INITIAL STATUS==========" << std::endl;
	gwen.showStatus("ClapTrap");
	zed.showStatus("ScavTrap");

	std::cout << "=======GWEN ATTACKS ZED==========" << std::endl;
	gwen.attack(zed.getName());
	zed.takeDamage(gwen.getAttackDamage());
	zed.showStatus("ScavTrap");
	zed.beRepaired(10);

	std::cout << "=======ZED ATTACKS GWEN==========" << std::endl;
	zed.attack(gwen.getName());
	gwen.takeDamage(zed.getAttackDamage());
	gwen.showStatus("ClapTrap");
	gwen.beRepaired(10);

	std::cout << "=======ZED GUARD GATE==========" << std::endl;
	zed.showStatus("ScavTrap");
	zed.guardGate();

	return 0;
}
