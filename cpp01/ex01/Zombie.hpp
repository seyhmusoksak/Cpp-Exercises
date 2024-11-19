/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 04:40:01 by soksak            #+#    #+#             */
/*   Updated: 2024/11/19 04:52:47 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie
{
	private:
		std::string	zombieName;

	public:
		Zombie( std::string zombieName );
		Zombie();
		void setName( std::string name );
		void announce( void );
		~Zombie();
};

Zombie*	zombieHorde(int N, std::string name);

#endif

