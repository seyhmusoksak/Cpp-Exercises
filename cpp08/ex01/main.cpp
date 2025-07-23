/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 01:30:27 by soksak            #+#    #+#             */
/*   Updated: 2025/07/19 18:06:12 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime> // For seeding the random number generator


int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL))); // Seed for random number generation
	unsigned int randomNumber;

	try
	{
		std::cout << "Creating a Span with 10000 elements." << std::endl;
		Span span(10000);
		for (int i = 0; i < 10000; ++i)
		{
			randomNumber = rand() % 20000; // Generate a random number between 0 and 9999
			std::cout << "Adding number: " << randomNumber << std::endl;
			span.addNumber(randomNumber);
		}
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}

	return 0;
}
