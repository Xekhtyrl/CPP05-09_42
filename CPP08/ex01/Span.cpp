/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:13:07 by lvodak            #+#    #+#             */
/*   Updated: 2024/08/05 18:53:23 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Default constructor
Span::Span() {
	_size = 42;
	_stored = 0;
	return; }

Span::Span(unsigned int size) {
	_size = size;
	_stored = 0;
	return; }

// Copy constructor
Span::Span(const Span &other) {
  (*this)._size = other.getSize();
  return;
}

// Copy assignment overload
Span &Span::operator=(const Span &rhs) {
  (void)rhs;
  return *this;
}

// Default destructor
Span::~Span() { return; }

void	Span::addNumber(int num) {
	if (_stored >= _size)
		throw std::exception();
	_container.push_back(num);
	_stored++;
}
void	Span::addNumber(std::vector<int>& add) {
	for (std::vector<int>::iterator it = add.begin(); it != add.end(); it++)
	{
		if (_stored++ >= _size)
			throw std::exception();
		_container.push_back(*it);
		// std::cout<<_stored<<" = "<<*it<<_container.at(_stored - 1)<<std::endl;
	}
		
}
int	Span::shortestSpan() {
	if (_stored <= 1)
		throw std::exception();
	int min = *max_element(this->_container.begin(), this->_container.end());
	sort(this->_container.begin(), this->_container.end());
	for (std::vector<int>::iterator it = _container.begin(); it + 1 != _container.end(); it++)
		if (*(it + 1) - *it < min)
			min = *(it + 1) - *it;
	return min;
}
int	Span::longestSpan() {
	if (_stored <= 1)
		throw std::exception();
	return *max_element(this->_container.begin(), this->_container.end()) - *min_element(this->_container.begin(), this->_container.end());
}
unsigned int Span::getSize() const {
	return _size;
}