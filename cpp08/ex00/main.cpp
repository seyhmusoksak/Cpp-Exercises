/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:18:38 by soksak            #+#    #+#             */
/*   Updated: 2025/07/12 19:27:54 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <deque>

int main()
{
	std::vector<int> vec;
	std::list<int> lst;
	std::deque<int> deq;

	for (int i = 0; i < 5; ++i)
		vec.push_back(i);
	for (int i = 0; i < 5; ++i)
		lst.push_back(i);
	for (int i = 0; i < 5; ++i)
		deq.push_back(i);

	std::vector<int>::iterator it;
	try {
		it = easyfind(vec, 3);
		std::cout << "Found value in vector: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "Trying to find a value that does not exist in the vector:" << std::endl;
	try {
		it = easyfind(vec, 10);
		std::cout << "Found value: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::list<int>::iterator lit;
	try {
		lit = easyfind(lst, 2);
		std::cout << "Found value in list: " << *lit << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "Trying to find a value that does not exist in the list:" << std::endl;
	try {
		lit = easyfind(lst, 10);
		std::cout << "Found value in list: " << *lit << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::deque<int>::iterator deq_it;
	try {
		deq_it = easyfind(deq, 4);
		std::cout << "Found value in deque: " << *deq_it << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Trying to find a value that does not exist in the deque:" << std::endl;
	try {
		deq_it = easyfind(deq, 10);
		std::cout << "Found value in deque: " << *deq_it << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
