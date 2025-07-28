/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 23:10:51 by soksak            #+#    #+#             */
/*   Updated: 2025/07/28 21:39:31 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc == 2) {
		BitcoinExchange exchange;

		if (!exchange.loadDatabase("data.csv")) {
			std::cerr << "Error: Could not load database." << std::endl;
			return 1;
		}
		exchange.processInput(argv[1]);
	}
	else
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
}
