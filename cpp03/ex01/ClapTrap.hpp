/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:40:19 by soksak            #+#    #+#             */
/*   Updated: 2025/01/15 05:12:41 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>


class ClapTrap
{
	protected:
		std::string		name;
		unsigned int	hitPts;
		unsigned int	energyPts;
		unsigned int	attackDamage;

	public:
		ClapTrap();
		ClapTrap(const std::string& n);
		ClapTrap(ClapTrap& t);
		ClapTrap& operator=(ClapTrap &other);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
