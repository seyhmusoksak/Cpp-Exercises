/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:40:01 by soksak            #+#    #+#             */
/*   Updated: 2025/07/25 02:19:16 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	std::cout << "<------Subject Main------->" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "<-- String Stack Test -->" << std::endl;
	MutantStack<std::string> mstackStr;
	mstackStr.push("Hello");
	mstackStr.push("World");

	std::cout << "Size of mstackStr: " << mstackStr.size() << std::endl;
	std::cout << "Elements in mstackStr:" << std::endl;
	MutantStack<std::string>::iterator rit = mstackStr.begin();
	MutantStack<std::string>::iterator rite = mstackStr.end();
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}

	std::cout << "<-- Normal Stack Test -->" << std::endl;
	std::stack<std::string> stackStr;
	stackStr.push("Hello");
	stackStr.push("World");
	std::cout << "Size of stackStr: " << stackStr.size() << std::endl;
	std::cout << "Elements in stackStr:" << std::endl;
	while (!stackStr.empty())
	{
		std::cout << stackStr.top() << std::endl;
		stackStr.pop();
	}
	return 0;
}
