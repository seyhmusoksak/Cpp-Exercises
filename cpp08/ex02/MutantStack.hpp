/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:08:43 by soksak            #+#    #+#             */
/*   Updated: 2025/07/23 22:54:06 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP


#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {}
		MutantStack(const MutantStack &other) : std::stack<T>(other) {}
		MutantStack& operator=(const MutantStack &other) {
			if (this != &other) {
				std::stack<T>::operator=(other);
			}
			return *this;
		}
		~MutantStack() {}
		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator const_iterator;
		typedef typename std::deque<T>::reverse_iterator reverse_iterator;
		typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;
		iterator begin() {
			return this->c.begin();
		}
		const_iterator begin() const {
			return this->c.begin();
		}
		iterator end() {
			return this->c.end();
		}
};

#endif
