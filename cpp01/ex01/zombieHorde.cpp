/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 04:27:29 by soksak            #+#    #+#             */
/*   Updated: 2024/11/19 05:03:33 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie*	hordeZombie = new Zombie[N];

	for (int i = 0; i < N; i++)
		hordeZombie[i].setName(name);
	return (hordeZombie);
}
