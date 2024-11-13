/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 00:36:09 by soksak            #+#    #+#             */
/*   Updated: 2024/11/13 01:45:47 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
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
		void firstNameField(Contact& contact);
		void lastNameField(Contact& contact);
		void nickNameField(Contact& contact);
		void phoneNumberField(Contact& contact);
		void darkestSecretField(Contact& contact);
};

#endif
