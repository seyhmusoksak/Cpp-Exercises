/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:39:39 by soksak            #+#    #+#             */
/*   Updated: 2025/01/16 04:26:46 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	ClapTrap gwen("Gwen");
	ScavTrap zed("Zed");
	FragTrap jinx("Jinx");

	std::cout << "=======INITIAL STATUS==========" << std::endl;
	gwen.showStatus("ClapTrap");
	zed.showStatus("ScavTrap");
	jinx.showStatus("FragTrap");

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

	std::cout << "=======JINX ATTACKS ZED==========" << std::endl;
	jinx.attack(zed.getName());
	zed.takeDamage(jinx.getAttackDamage());
	zed.showStatus("ScavTrap");
	zed.guardGate();

	std::cout << "=======JINX HIGH FIVES==========" << std::endl;
	jinx.showStatus("FragTrap");
	jinx.highFivesGuys();
}
