/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 20:23:49 by soksak            #+#    #+#             */
/*   Updated: 2025/06/22 01:13:01 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>

Array<T>::Array() : arr(NULL), size(0) {
}

template <typename T>
Array<T>::Array(const Array& other) : size(other.size) {
	if (size == 0) {
		arr = NULL;
	} else {
		arr = new T[size];
		for (unsigned int i = 0; i < size; ++i) {
			arr[i] = other.arr[i];
		}
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other) {
		if (arr) {
			delete[] arr;
		}
		size = other.size;
		if (size == 0) {
			arr = NULL;
		} else {
			arr = new T[size];
			for (unsigned int i = 0; i < size; ++i) {
				arr[i] = other.arr[i];
			}
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	if (arr) {
		delete[] arr;
	}
}

template <typename T>
Array<T>::Array(unsigned int n) : size(n) {
	if (n == 0) {
		arr = NULL;
	} else {
		arr = new T[n];
	}
}

template <typename T>
T& Array<T>::operator[](unsigned int index) const {
	if (index >= size) {
		throw std::exception();
	}
	return arr[index];
}

template <typename T>
unsigned int Array<T>::getSize() const {
	return size;
}
