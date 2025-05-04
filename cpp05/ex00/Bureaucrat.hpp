/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 04:50:07 by soksak            #+#    #+#             */
/*   Updated: 2025/05/04 06:14:20 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		const std::string name;
		int grade;

		public:
		Bureaucrat(void);
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat const	&operator=(Bureaucrat const &copy);
		~Bureaucrat(void);
		std::string getName() const;
		int getGrade() const;
		void setGrade(int grade);
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif
