/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 22:00:48 by soksak            #+#    #+#             */
/*   Updated: 2025/07/28 22:13:15 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP


#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>

class RPN {
private:
	std::stack<int> _stack;
	bool isOperator(const std::string &token);
	int performOperation(int a, int b, const std::string &op);

public:
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();
	void evaluate(const std::string &expression);


	class UnknownOperatorException : public std::exception {
	public:
		const char *what() const throw();
	};

	class DivisionByZeroException : public std::exception {
	public:
		const char *what() const throw();
	};

	class InvalidExpressionException : public std::exception {
	public:
		const char *what() const throw();
	};

	class NotEnoughOperandsException : public std::exception {
	public:
		const char *what() const throw();
	};

};

#endif
