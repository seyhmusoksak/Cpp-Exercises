/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 03:21:03 by soksak            #+#    #+#             */
/*   Updated: 2025/01/14 00:12:11 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int			value;
		const static int	fract;
	public:
		Fixed();
		Fixed(int const number);
		Fixed(float const number);
		~Fixed();
		Fixed(const Fixed& cpy);
		Fixed& operator=(const Fixed& t);
		void setRawBits(int const raw);
		int getRawBits(void) const;
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);

#endif
