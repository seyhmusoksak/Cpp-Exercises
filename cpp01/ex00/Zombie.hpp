/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 04:40:01 by soksak            #+#    #+#             */
/*   Updated: 2024/11/17 05:47:14 by soksak           ###   ########.fr       */
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
		void announce( void );
		~Zombie();
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif

