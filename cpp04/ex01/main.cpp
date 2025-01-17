/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 06:13:47 by soksak            #+#    #+#             */
/*   Updated: 2025/01/17 09:16:40 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout <<"----------PDF Example Main---------" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;


	std::cout << "------------Main Test-------------" << std::endl;
	Animal **animals = new Animal*[10];

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


	std::cout << "------Deep Copy With Static------" << std::endl;
	Cat c;

	for (int i = 0; i < 100; i++)
		c.setIdea(i, "Meow");

	Cat d(c);

	std::cout << "c's first idea: " << c.getIdea(0) << std::endl;
	std::cout << "d's first idea: " << d.getIdea(0) << std::endl;

	std::cout << "------Deep Copy With Pointer------" << std::endl;

	Dog *a = new Dog();
	Dog *b = new Dog();

	for (int i = 0; i < 100; i++)
		a->setIdea(i, "idea");

	*b = *a;

	std::cout << "a's first idea: " << a->getIdea(0) << std::endl;
	std::cout << "b's first idea: " << b->getIdea(0) << std::endl;
	std::cout << "Changing a's first idea" << std::endl;
	a->setIdea(0, "new idea");
	std::cout << "a's first idea: " << a->getIdea(0) << std::endl;
	std::cout << "b's first idea: " << b->getIdea(0) << std::endl;

	delete a;
	delete b;

}
