/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 01:30:27 by soksak            #+#    #+#             */
/*   Updated: 2025/07/25 02:56:07 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime> // For seeding the random number generator


int main()
{
	std::cout << "<------Subject Main------->" << std::endl;

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	std::srand(std::time(0));
	unsigned int randomNumber;
	try
	{
		std::cout << "<--- Creating a Span with 10000 elements. -->" << std::endl;
		Span span(10000);
		for (int i = 0; i < 10000; ++i)
		{
			randomNumber = rand() % 10000;
			span.addNumber(randomNumber);
		}
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}

	std::cout << "<-- Adding only one number -->" << std::endl;
	try
	{
		Span sp3 = Span(10);
		sp3.addNumber(1);
		std::cout << sp3.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "<-- Add more than 10 numbers with vector -->" << std::endl;
	try
	{
		Span sp4 = Span(10);
		std::vector<int> vec;
		for (int i = 0; i < 10; ++i)
		{
			vec.push_back(i);
		}
		sp4.addNumber(vec.begin(), vec.end());
		std::cout << "Shortest span: " << sp4.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp4.longestSpan() << std::endl;
		std::cout << "Adding one more number:" << std::endl;
		sp4.addNumber(5);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	return 0;
}
