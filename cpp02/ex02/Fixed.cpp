/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 03:21:05 by soksak            #+#    #+#             */
/*   Updated: 2025/01/12 07:24:48 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::fract = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(int const number)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = (number << this->fract);
}

Fixed::Fixed(float const number)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(number * (1 << this->fract));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed& Fixed::operator=(const Fixed& t)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &t)
	{
		this->value = t.getRawBits();
	}
	return *this;
}

void Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

float Fixed::toFloat(void) const
{
	return ((float)this->value / (1 << this->fract));
}

int Fixed::toInt(void) const
{
	return (this->value >> this->fract);
}

bool Fixed::operator>(const Fixed& t) const
{
	return (this->value > t.getRawBits());
}

bool Fixed::operator<(const Fixed& t) const
{
	return (this->value < t.getRawBits());
}

bool Fixed::operator>=(const Fixed& t) const
{
	return (this->value >= t.getRawBits());
}

bool Fixed::operator<=(const Fixed& t) const
{
	return (this->value <= t.getRawBits());
}

bool Fixed::operator==(const Fixed& t) const
{
	return (this->value == t.getRawBits());
}

bool Fixed::operator!=(const Fixed& t) const
{
	return (this->value != t.getRawBits());
}

Fixed Fixed::operator+(const Fixed& t) const
{
	return Fixed(this->toFloat() + t.toFloat());
}

Fixed Fixed::operator-(const Fixed& t) const
{
	return Fixed(this->toFloat() - t.toFloat());
}

Fixed Fixed::operator*(const Fixed& t) const
{
	return Fixed(this->toFloat() * t.toFloat());
}

Fixed Fixed::operator/(const Fixed& t) const
{
	return Fixed(this->toFloat() / t.toFloat());
}

Fixed& Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->setRawBits(this->getRawBits() + 1);
	return tmp;
}

Fixed& Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->setRawBits(this->getRawBits() - 1);
	return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
}

std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return o;
}
