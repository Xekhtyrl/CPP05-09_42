/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:00:31 by lvodak            #+#    #+#             */
/*   Updated: 2024/07/31 21:20:16 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP_
#define SERIALIZER_HPP_

#include <iostream>
#include "data.h"
// Class declaration

class Serializer {
 public:
	static uintptr_t	serialize(Data *ptr);
	static Data	*deserialize(uintptr_t raw);
 private:
  Serializer();
  Serializer(const Serializer &other);
  Serializer &operator=(const Serializer &rhs);
  ~Serializer();
  
};

#endif // SERIALIZER_HPP_
