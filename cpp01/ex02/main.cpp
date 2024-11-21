/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:08:44 by soksak            #+#    #+#             */
/*   Updated: 2024/11/22 02:26:31 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string*	strPtr = &str;
	std::string&	strRef = str;

	std::cout << "Memory Addresses" << std::endl;
	std::cout << "str: " << &str << std::endl;
	std::cout << "strPtr: " << strPtr << std::endl;
	std::cout << "strRef: " << &strRef << std::endl;

	std::cout << "Values" << std::endl;
	std::cout << "str: " << str << std::endl;
	std::cout << "strPtr: " << *strPtr << std::endl;
	std::cout << "strRef: " << strRef << std::endl;
}

