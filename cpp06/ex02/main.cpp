/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:38:23 by soksak            #+#    #+#             */
/*   Updated: 2025/05/26 16:57:27 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base* generate()
{
	std::srand(time(0));
	int random = std::rand() % 3;
	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;
	}
	catch (std::exception &e)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
			(void)b;
		}
		catch (std::exception &e)
		{
			try
			{
				C& c = dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
				(void)c;
			}
			catch (std::exception& e)
			{
				std::cout << "Unknown type" << std::endl;
			}
		}
	}
}


int main()
{
	Base* basePtr = generate();
	std::cout << "Identify by pointer: ";
	identify(basePtr);

	std::cout << "Identify by reference: ";
	identify(*basePtr);

	delete basePtr;
	return 0;
}




