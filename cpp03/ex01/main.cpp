/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:39:39 by soksak            #+#    #+#             */
/*   Updated: 2025/01/15 05:20:48 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap Gwen("Gwen");

	Gwen.attack("Zed");
	Gwen.takeDamage(5);
	Gwen.beRepaired(5);
	Gwen.attack("Zed");
	Gwen.takeDamage(5);
	Gwen.takeDamage(5);
	Gwen.beRepaired(5);
}
