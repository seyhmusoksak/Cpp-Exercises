/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 02:50:33 by soksak            #+#    #+#             */
/*   Updated: 2025/05/27 09:44:02 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"



static bool isCharLiteral(const std::string &literal)
{
	return literal.length() == 3 &&
		   literal[0] == '\'' &&
		   literal[2] == '\'';
}

static bool isPseudoLiteral(const std::string &literal)
{
	return literal == "nan" || literal == "nanf" ||
		   literal == "+inf" || literal == "-inf" ||
		   literal == "+inff" || literal == "-inff";
}

static bool isFloatLiteral(const std::string &literal)
{
	if (literal == "+inff" || literal == "-inff" || literal == "nanf")
		return true;

	if (literal.empty() || literal[literal.length() - 1] != 'f')
		return false;

	std::string numPart = literal.substr(0, literal.length() - 1);

	if (numPart.find('.') == std::string::npos)
		return false;

	std::istringstream iss(numPart);
	float f;
	return (iss >> f) && iss.eof();
}

static bool isDoubleLiteral(const std::string &literal)
{
	if (isPseudoLiteral(literal))
		return true;

	std::istringstream iss(literal);
	double d;

	return (iss >> d) &&
		   iss.eof() &&
		   literal.find('.') != std::string::npos;
}

static bool isIntLiteral(const std::string &literal)
{
	std::istringstream iss(literal);
	int i;
	return (iss >> i) && iss.eof();
}

static void printChar(double val)
{
	std::cout << "char: ";

	if (std::isnan(val) || val < 0 || val > 127)
		std::cout << "impossible" << std::endl;

	else if (!std::isprint(static_cast<char>(val)))
		std::cout << "Non displayable" << std::endl;

	else
		std::cout << "'" << static_cast<char>(val) << "'" << std::endl;
}

static void printInt(double val)
{
	std::cout << "int: ";

	if (std::isnan(val) ||
		val < std::numeric_limits<int>::min() ||
		val > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;

	else
		std::cout << static_cast<int>(val) << std::endl;
}

static void printFloat(double val)
{
	std::cout << "float: ";

	if (std::isnan(val))
		std::cout << "nanf" << std::endl;

	else if (std::isinf(val))
		std::cout << (val < 0 ? "-inff" : "+inff") << std::endl;

	else
	{
		float f = static_cast<float>(val);
		std::cout << f;
		if (f == static_cast<int>(f))
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
}

static void printDouble(double val)
{
	std::cout << "double: ";

	if (std::isnan(val))
		std::cout << "nan" << std::endl;

	else if (std::isinf(val))
		std::cout << (val < 0 ? "-inf" : "+inf") << std::endl;

	else
	{
		std::cout << val;
		if (val == static_cast<int>(val))
			std::cout << ".0";
		std::cout << std::endl;
	}
}



static LiteralType getLiteralType(const std::string &literal)
{
	if (literal.length() == 1 &&
		std::isprint(literal[0]) &&
		!std::isdigit(literal[0]))
		return CHAR;

	if (isCharLiteral(literal))   return CHAR;
	if (isIntLiteral(literal))    return INT;
	if (isFloatLiteral(literal))  return FLOAT;
	if (isDoubleLiteral(literal)) return DOUBLE;

	return IMPOSSIBLE;
}


void ScalarConverter::convert(const std::string &literal)
{
	double value;
	LiteralType type;

	try
	{
		type = getLiteralType(literal);

		switch (type)
		{
			case CHAR:
				value = (literal.length() == 1) ?
					static_cast<double>(literal[0]) :
					static_cast<double>(literal[1]);
				break;

			case INT:
				value = static_cast<double>(std::atoi(literal.c_str()));
				break;

			case FLOAT:
				value = static_cast<double>(std::atof(literal.c_str()));
				break;

			case DOUBLE:
				value = std::atof(literal.c_str());
				break;
			case IMPOSSIBLE:
				throw ScalarConverter::ImpossibleConversion();
		}

		printChar(value);
		printInt(value);
		printFloat(value);
		printDouble(value);
	}
	catch (std::exception &e)

	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

const char* ScalarConverter::ImpossibleConversion::what() const throw()
{
	return "Conversion is impossible for all types(char, int, float, double).";
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &)
{
	return *this;
}
