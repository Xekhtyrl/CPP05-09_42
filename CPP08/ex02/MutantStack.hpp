/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:22:15 by lvodak            #+#    #+#             */
/*   Updated: 2024/08/05 21:56:06 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

// Class declaration
template<typename T>
class MutantStack : public std::stack<T> {
 public:
 	// class iterator;
	MutantStack() : std::stack<T>() {};
	MutantStack(const MutantStack &other) : std::stack<T>(other) {};
	MutantStack &operator=(const MutantStack &rhs) {
		this->c = rhs.c;
		return *this;
	};
	~MutantStack() {};

	typedef typename std::stack<T>::container_type Container;
	typedef typename Container::iterator iterator;

	iterator begin(){
		return this->c.begin();
	};
	iterator end(){
		return this->c.end();
	};

 private:
  
};
