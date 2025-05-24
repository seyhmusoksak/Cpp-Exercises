/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 00:22:19 by soksak            #+#    #+#             */
/*   Updated: 2025/05/24 16:41:18 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		RobotomyRequestForm const &operator=(RobotomyRequestForm const &copy);
		~RobotomyRequestForm();
		void execute(Bureaucrat const &executor) const;
		class RobotomyFailedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};
