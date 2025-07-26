/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak < soksak@student.42istanbul.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 23:10:51 by soksak            #+#    #+#             */
/*   Updated: 2025/07/26 23:17:20 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) {
	// Check for exactly one input argument
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
		return 1;
	}

	// Create BitcoinExchange object
	BitcoinExchange exchange;

	// Load the exchange rate database
	if (!exchange.loadDatabase("data.csv")) {
		std::cerr << "Error: could not load exchange rate database (data.csv)." << std::endl;
		return 1;
	}

	// Process the input file (e.g., input.txt)
	exchange.processInput(argv[1]);

	return 0;
}
