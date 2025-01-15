/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:39:39 by soksak            #+#    #+#             */
/*   Updated: 2025/01/15 06:22:23 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap gwen("Gwen");
	ClapTrap zed("Zed");

	gwen.showStatus("ClapTrap");
	zed.showStatus("ClapTrap");

	gwen.attack(zed.getName());
	zed.takeDamage(gwen.getAttackDamage());
	zed.showStatus("ClapTrap");
	gwen.beRepaired(10);


	zed.attack(gwen.getName());
	gwen.takeDamage(zed.getAttackDamage());
	gwen.showStatus("ClapTrap");
	gwen.beRepaired(10);
}
