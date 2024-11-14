/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 00:36:09 by soksak            #+#    #+#             */
/*   Updated: 2024/11/14 03:54:01 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact _contacts[8];
		int _nbContacts;
		int _oldIndex;
		int getContactIndex();
	public:
		PhoneBook();
		void addContact();
		void displayContacts();
		void searchContact();
};

#endif
