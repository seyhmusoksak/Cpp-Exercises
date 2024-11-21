/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 01:55:39 by soksak            #+#    #+#             */
/*   Updated: 2024/11/22 01:59:37 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class	HumanB
{
	private:
		std::string	humanName;
		Weapon*		weapon;
	public:
		HumanB(std::string name);
		~HumanB(void);
		void	setWeapon(Weapon& weapon);
		void	attack(void);
};

#endif
