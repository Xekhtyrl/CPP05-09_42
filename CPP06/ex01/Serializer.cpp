/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:00:15 by lvodak            #+#    #+#             */
/*   Updated: 2024/07/31 21:24:23 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Default constructor
Serializer::Serializer() { return; }

// Copy constructor
Serializer::Serializer(const Serializer &other) {
  *this = other;
  return;
}

// Copy assignment overload
Serializer &Serializer::operator=(const Serializer &rhs) {
  (void)rhs;
  return *this;
}

// Default destructor
Serializer::~Serializer() { return; }

uintptr_t	Serializer::serialize(Data *ptr){
	uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
	return (raw);
}
Data	*Serializer::deserialize(uintptr_t raw){
	Data	*ptr = reinterpret_cast<Data *>(raw);
	return (ptr);
}