/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 05:38:11 by soksak            #+#    #+#             */
/*   Updated: 2024/11/17 06:06:56 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << "---Stack Usage---" << std::endl;
	Zombie ZombieZero;
	Zombie zombieOne("zombieOne");
	Zombie zombieTwo("zombieTwo");

	ZombieZero.announce();
	zombieOne.announce();
	zombieTwo.announce();
	randomChump("ChumpZombie");

	std::cout << std::endl;
	std::cout << "---Heap Usage---" << std::endl;

	Zombie *heapZombie;

	heapZombie = newZombie("heapZombie");
	heapZombie->announce();
	delete heapZombie;

	return (0);
}
