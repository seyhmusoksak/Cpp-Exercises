/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 01:17:04 by soksak            #+#    #+#             */
/*   Updated: 2025/07/15 01:31:25 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>

class Span
{
	private:
		unsigned int _N;
		std::vector<int> _numbers;
	public:
		// Constructors and Destructor
		Span(unsigned int N);
		~Span();
		Span(const Span &other);
		Span &operator=(const Span &other);

		// Members
		void addNumber(int number);
		int shortestSpan();
		int longestSpan();
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);


		// Exceptions
		class SpanFullException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class NoSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};




#endif
