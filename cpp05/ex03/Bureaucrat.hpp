/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 04:50:07 by soksak            #+#    #+#             */
/*   Updated: 2025/05/23 03:05:38 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;

		public:
		Bureaucrat();
		Bureaucrat(std::string const &name, int const &grade);
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat const	&operator=(Bureaucrat const &copy);
		~Bureaucrat();
		void signForm(AForm &form);
		void executeForm(AForm const &form);
		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif
