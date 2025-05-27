/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:51:21 by soksak            #+#    #+#             */
/*   Updated: 2025/05/27 09:41:01 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <cctype>
#include <cmath>
#include <cstdlib>


enum LiteralType {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	IMPOSSIBLE
};


class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);

	public:
		static void convert(const std::string &input);
		class ImpossibleConversion : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif
