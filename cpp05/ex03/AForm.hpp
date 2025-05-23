/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 03:15:12 by soksak            #+#    #+#             */
/*   Updated: 2025/05/23 04:49:22 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"


class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int executeGrade;
	public:
		AForm();
		AForm(std::string name, int signGrade, int executeGrade);
		AForm(AForm const &copy);
		AForm const	&operator=(AForm const &copy);
		virtual ~AForm();
		std::string getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		void beSigned(Bureaucrat const &bureaucrat);
		virtual	void	execute(Bureaucrat const &executor) const = 0;
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
		class FormIsNotSignedException : public std::exception
		{
			public:
			virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os,  AForm const &form);

#endif
