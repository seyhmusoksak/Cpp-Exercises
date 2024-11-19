/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 05:38:11 by soksak            #+#    #+#             */
/*   Updated: 2024/11/19 05:39:01 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie*	hordeZombie;

	hordeZombie = zombieHorde(5, "Zombie");
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Index " << i << ": ";
		hordeZombie[i].announce();
	}
	delete [] hordeZombie;
	std::cout << "All zombies have been destroyed." << std::endl;
	return (0);
}
