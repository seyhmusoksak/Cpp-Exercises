/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 01:28:15 by soksak            #+#    #+#             */
/*   Updated: 2024/11/22 01:39:08 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class	Weapon
{
	private:
		std::string	type;
	public:
		Weapon(std::string weaponType);
		~Weapon(void);
		const std::string&	getType(void);
		void				setType(std::string weaponType);
};

#endif
