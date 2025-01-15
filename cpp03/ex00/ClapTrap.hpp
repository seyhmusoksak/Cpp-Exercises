/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:40:19 by soksak            #+#    #+#             */
/*   Updated: 2025/01/15 06:15:16 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>


class ClapTrap
{
	private:
		std::string name;
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
		void showStatus(std::string const &className);
		std::string getName() const;
		unsigned int getHitPts() const;
		unsigned int getEnergyPts() const;
		unsigned int getAttackDamage() const;
};

#endif
