/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:22:49 by lvodak            #+#    #+#             */
/*   Updated: 2024/08/01 17:59:22 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template<typename T>

void	swap(T & a, T & b) {
	T c = a;

	a = b;
	b = (T&)c;
};

template<typename T>
T &min(T & a, T & b) {
	if (a >= b)
		return b;
	return a; 
};

template<typename T>
T &max(T & a, T & b) {
	if (a <= b)
		return b;
	return a; 
};