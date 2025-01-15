/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:39:39 by soksak            #+#    #+#             */
/*   Updated: 2025/01/15 06:17:38 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap Gwen("Gwen");
	ClapTrap Zed("Zed");

	Gwen.showStatus("ClapTrap");
	Zed.showStatus("ClapTrap");

	Gwen.attack(Zed.getName());
	Zed.takeDamage(Gwen.getAttackDamage());
	Zed.showStatus("ClapTrap");
	Gwen.beRepaired(10);


	Zed.attack(Gwen.getName());
	Gwen.takeDamage(Zed.getAttackDamage());
	Gwen.showStatus("ClapTrap");
	Gwen.beRepaired(10);
}
