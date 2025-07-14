/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 01:30:27 by soksak            #+#    #+#             */
/*   Updated: 2025/07/15 01:36:13 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


int main()
{

	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(4);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}

	return 0;
}
