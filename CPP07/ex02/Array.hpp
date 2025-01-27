/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:27:43 by lvodak            #+#    #+#             */
/*   Updated: 2024/08/01 21:04:07 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
#include <iostream>

template <class T>
class Array {
	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T>& oth);
		Array<T> &operator=(const Array<T>& oth);
		~Array();
		T &operator[](unsigned int);
		unsigned int size() const;
		class SizeTooHighException : public std::exception{
			virtual const char *what() const throw();
		};
	private:
		T	*_array;
		unsigned int _size;
};

template <class T>
Array<T>::Array() {
	_array = new T[0];
	_size = 0;
	return;
};

template <class T>
Array<T>::Array(unsigned int n) {
	_array = new T[n];
	_size = n;
	return;
};

template <class T>
Array<T>::Array(const Array<T>& oth) {
	_array = new T[oth.size()];
	_size = oth.size();
	return;
};
template <class T>
Array<T> &Array<T>::operator=(const Array<T>& oth) {
	_array = new T[oth.size()];
	_size = oth.size();
	return *this;
};
template <class T>
Array<T>::~Array(){
	delete[] _array;
	return;
};
template <class T>
T &Array<T>::operator[](unsigned int n) {
	if (n >= _size)
		throw SizeTooHighException();
	return (_array[n]);

};

template <class T>
unsigned int Array<T>::size() const {
	return _size;
};

template <class T>
const char*	Array<T>::SizeTooHighException::what() const throw() { 
	return "Exception: Size too High";
}