/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 18:44:39 by lvodak            #+#    #+#             */
/*   Updated: 2024/08/01 19:16:40 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
void	iter(T* array, unsigned int length, void (*f)(T&)) {
	if (!f)
		return ;
	for (unsigned int i = 0; i < length; i++)
		f(array[i]);
}