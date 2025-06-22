/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:31:38 by soksak            #+#    #+#             */
/*   Updated: 2025/06/15 18:33:32 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"


void printInt(int &n) {
	std::cout << n << " ";
}

void printChar(char &c) {
	std::cout << c << " ";
}

void printString(std::string &s) {
	std::cout << s << " ";
}

void printAdress(size_t &n) {
	std::cout << &n << " ";
}

int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	std::string stringArray[] = {"Hello", "World", "42", "C++", "Iter"};

	std::cout << "Integer Array: ";
	iter(intArray, 5, printInt);
	std::cout << std::endl;

	std::cout << "Character Array: ";
	iter(charArray, 5, printChar);
	std::cout << std::endl;

	std::cout << "String Array: ";
	iter(stringArray, 5, printString);
	std::cout << std::endl;


	size_t sizeArray[] = {10, 20, 30, 40, 50};
	std::cout << "Size_t Array Addresses: ";
	iter(sizeArray, 5, printAdress);
	std::cout << std::endl;

	return 0;
}
