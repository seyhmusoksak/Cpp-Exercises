/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 01:20:48 by soksak            #+#    #+#             */
/*   Updated: 2025/07/15 01:32:37 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"



Span::Span(unsigned int N) : _N(N) {

}

Span::~Span() {
}

Span::Span(const Span &other) : _N(other._N), _numbers(other._numbers) {
}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		_N = other._N;
		_numbers = other._numbers;
	}
	return *this;
}

void Span::addNumber(int number) {
	if (_numbers.size() >= _N) {
		throw SpanFullException();
	}
	_numbers.push_back(number);
}


int		Span::shortestSpan()
{
	if (_numbers.size() <= 1)
		throw NoSpanException();
	std::vector<int> tmp = _numbers;
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return (min);
}

int		Span::longestSpan()
{
	if (_numbers.size() <= 1)
		throw NoSpanException();
	std::vector<int> tmp = _numbers;
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}


void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (std::distance(begin, end) + _numbers.size() > _N) {
		throw SpanFullException();
	}
	_numbers.insert(_numbers.end(), begin, end);
}

const char* Span::SpanFullException::what() const throw() {
	return "Span is full, cannot add more numbers";
}

const char* Span::NoSpanException::what() const throw() {
	return "No span can be found, not enough numbers";
}

