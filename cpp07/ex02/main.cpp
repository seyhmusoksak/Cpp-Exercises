/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:31:38 by soksak            #+#    #+#             */
/*   Updated: 2025/06/22 01:21:35 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{

	Array<int> intArray(5);
	for (unsigned int i = 0; i < intArray.getSize(); ++i)
	{
		intArray[i] = i * 10;
	}

	try
	{
		std::cout << "Integer Array:" << std::endl;
		for (unsigned int i = 0; i < intArray.getSize(); ++i)
		{
			std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
		}
		std::cout << "intArray[5] = " << intArray[5] << std::endl; // This will throw an exception
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception has been thrown." << '\n';
	}

	try
	{
		Array<std::string> strArray(3);
		strArray[0] = "Hello";
		strArray[1] = "World";
		strArray[2] = "!";

		std::cout << "\nString Array:" << std::endl;
		for (unsigned int i = 0; i < strArray.getSize(); ++i)
		{
			std::cout << "strArray[" << i << "] = " << strArray[i] << std::endl;
		}
		std::cout << "strArray[3] = " << strArray[3] << std::endl; // This will throw an exception
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception thrown." << '\n';
	}

	return 0;
}
