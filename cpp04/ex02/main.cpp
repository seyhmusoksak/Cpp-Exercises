/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 06:13:47 by soksak            #+#    #+#             */
/*   Updated: 2025/01/17 09:15:46 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "------------Main Test-------------" << std::endl;
	AAnimal **animals = new AAnimal*[10];

	for (int i = 0; i < 10; i++)
	{
		if (i >= 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << animals[i]->getType() << " says: ";
		animals[i]->makeSound();
	}
	for (int i = 0; i < 10; i++)
		delete animals[i];

	delete [] animals;
	return (0);
}
