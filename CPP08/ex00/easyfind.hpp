/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:31:49 by lvodak            #+#    #+#             */
/*   Updated: 2024/08/02 19:25:48 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>

template <typename T>
// template <template <typename> typename T>
typename T::iterator easyfind(T &cont, int n) {
	typename T::iterator val = std::find(cont.begin(), cont.end(), n);
	if (val == cont.end())
		throw std::exception();
	return (val);
};