/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 22:01:30 by soksak            #+#    #+#             */
/*   Updated: 2025/07/28 22:22:15 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &other) : _stack(other._stack) {}
RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		this->_stack = other._stack;
	}
	return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string &token)
{
	return token == "+" || token == "-" || token == "*" || token == "/";
}

int RPN::performOperation(int a, int b, const std::string &op)
{
	if (op == "+")
		return a + b;
	if (op == "-")
		return a - b;
	if (op == "*")
		return a * b;
	if (op == "/")
	{
		if (b == 0)
		{
			throw DivisionByZeroException();
		}
		return a / b;
	}
	throw UnknownOperatorException();
}

void RPN::evaluate(const std::string &expression)
{
	std::istringstream iss(expression.c_str());
	std::string token;

	while (iss >> token)
	{
		if (isdigit(token[0]))
		{
			_stack.push(static_cast<int>(std::atoi(token.c_str())));
		}
		else if (isOperator(token))
		{
			if (_stack.size() < 2)
			{
				throw NotEnoughOperandsException();
			}
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			int result = performOperation(a, b, token);
			_stack.push(result);
		}
		else
		{
			throw UnknownOperatorException();
		}
	}

	if (_stack.size() != 1)
	{
		throw InvalidExpressionException();
	}

	std::cout << "Result: " << _stack.top() << std::endl;
}

const char *RPN::InvalidExpressionException::what() const throw()
{
	return "Error: Invalid expression";
}

const char *RPN::NotEnoughOperandsException::what() const throw()
{
	return "Error: Not enough operands";
}

const char *RPN::DivisionByZeroException::what() const throw()
{
	return "Error: Division by zero";
}

const char *RPN::UnknownOperatorException::what() const throw()
{
	return "Error: Unknown operator";
}
