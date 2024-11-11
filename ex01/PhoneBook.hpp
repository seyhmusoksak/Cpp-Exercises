/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 00:36:09 by soksak            #+#    #+#             */
/*   Updated: 2024/11/12 01:27:34 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact _contacts[8];
		int _nbContacts;
		int _oldIndex;
	public:
		PhoneBook(void);
		void addContact(void);
		void displayContacts(void);
		void searchContact(int index);
};

#endif
