/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 04:56:39 by soksak            #+#    #+#             */
/*   Updated: 2025/01/15 05:16:22 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool		guardMode;
	public:
		ScavTrap();
		ScavTrap(const std::string& n);
		ScavTrap(ScavTrap& t);
		ScavTrap& operator=(ScavTrap &other);
		~ScavTrap();
		void attack(const std::string& target);
		void guardGate();
};

#endif
