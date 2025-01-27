/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:12:44 by lvodak            #+#    #+#             */
/*   Updated: 2024/08/05 18:52:03 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP_
#define SPAN_HPP_

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>

// Class declaration
class Span {
 public:
	Span();
	Span(unsigned int);
	Span(const Span &other);
	Span &operator=(const Span &rhs);
	~Span();
	void	addNumber(int);
	void	addNumber(std::vector<int>&);
	int	shortestSpan();
	int	longestSpan();
	unsigned int getSize() const;

 private:
	unsigned int	_size;
	unsigned int	_stored;
	std::vector<int>	_container;
};

#endif // SPAN_HPP_
