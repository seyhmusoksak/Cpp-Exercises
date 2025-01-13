/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 03:21:03 by soksak            #+#    #+#             */
/*   Updated: 2025/01/14 00:12:23 by soksak           ###   ########.fr       */
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
		bool operator>(const Fixed& t) const;
		bool operator<(const Fixed& t) const;
		bool operator>=(const Fixed& t) const;
		bool operator<=(const Fixed& t) const;
		bool operator==(const Fixed& t) const;
		bool operator!=(const Fixed& t) const;
		Fixed operator+(const Fixed& t) const;
		Fixed operator-(const Fixed& t) const;
		Fixed operator*(const Fixed& t) const;
		Fixed operator/(const Fixed& t) const;
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);
		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);

#endif
