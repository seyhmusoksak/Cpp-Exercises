/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:39:52 by soksak            #+#    #+#             */
/*   Updated: 2025/05/26 16:08:13 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


int main()
{
	Data* Alice = new Data();
	Alice->value = 42;
	Alice->name = "Alice";

	std::cout << "<--Serialized-->" << std::endl;
	uintptr_t raw = Serializer::serialize(Alice);
	std::cout << "Serialized uintptr_t: " << raw << std::endl;

	std::cout << "<--Deserialized-->" << std::endl;
	Data* deserializedData = Serializer::deserialize(raw);
	std::cout << "Value: " << deserializedData->value << std::endl;
	std::cout << "Name: " << deserializedData->name << std::endl;

	delete Alice;

	return 0;
}
