/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 05:42:20 by soksak            #+#    #+#             */
/*   Updated: 2025/01/17 10:18:56 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal
{
	protected:
		std::string type;
	public:
		AAnimal();
		AAnimal(const AAnimal &copy);
		AAnimal &operator=(const AAnimal &copy);
		virtual ~AAnimal();
		std::string getType() const;
		virtual void makeSound() const = 0;
};

#endif
