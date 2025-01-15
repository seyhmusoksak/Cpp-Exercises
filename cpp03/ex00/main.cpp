/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:39:39 by soksak            #+#    #+#             */
/*   Updated: 2025/01/15 04:23:14 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap Gwen("Gwen");

	Gwen.attack("Zed");
	Gwen.takeDamage(5);
	Gwen.beRepaired(5);
	Gwen.attack("Zed");
	Gwen.takeDamage(5);
	Gwen.takeDamage(5);
	Gwen.beRepaired(5);
	Gwen.takeDamage(5);
}
