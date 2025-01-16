/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:39:39 by soksak            #+#    #+#             */
/*   Updated: 2025/01/16 04:01:18 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap gwen("Gwen");
	ClapTrap zed("Zed");

	std::cout << "=======INITIAL STATUS==========" << std::endl;
	gwen.showStatus("ClapTrap");
	zed.showStatus("ClapTrap");

	std::cout << "=======GWEN ATTACKS ZED==========" << std::endl;
	gwen.attack(zed.getName());
	zed.takeDamage(gwen.getAttackDamage());
	zed.showStatus("ClapTrap");
	zed.beRepaired(10);

	std::cout << "=======ZED ATTACKS GWEN==========" << std::endl;
	zed.attack(gwen.getName());
	gwen.takeDamage(zed.getAttackDamage());
	gwen.showStatus("ClapTrap");
	gwen.beRepaired(10);
}
