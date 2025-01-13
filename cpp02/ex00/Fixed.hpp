/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 03:21:03 by soksak            #+#    #+#             */
/*   Updated: 2025/01/14 00:09:52 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int			value;
		static const int	fract;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& cpy);
		Fixed& operator=(const Fixed& t);
		void setRawBits(int const raw);
		int getRawBits(void) const;
};

#endif
