/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 00:51:25 by soksak            #+#    #+#             */
/*   Updated: 2024/11/26 02:52:18 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;

		bool	validateAlphabetic(const std::string &str) const;
		bool	validateNumeric(const std::string &str) const;
		bool	validateNickname(const std::string &str) const;
		bool	validateDarkestSecret(const std::string &str) const;
		int 	getInput(std::string &input, const std::string &prompt);

	public:
		Contact(void);
		~Contact(void);
		bool setFirstName(void);
		bool setLastName(void);
		bool setNickName(void);
		bool setPhoneNumber(void);
		bool setDarkestSecret(void);
		std::string getFirstName(void) const;
		std::string getLastName(void) const;
		std::string getNickName(void) const;
		std::string getPhoneNumber(void) const;
		std::string getDarkestSecret(void) const;
};

#endif
