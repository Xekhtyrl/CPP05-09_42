/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:24:34 by lvodak            #+#    #+#             */
/*   Updated: 2024/07/31 21:28:18 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
	Data	Test;
	Data	*ret;
	uintptr_t ui = Serializer::serialize(&Test);
	ret = Serializer::deserialize(ui);
	std::cout<<"Test = "<<&Test<<"\nui = "<<ui<<"\nret = "<<ret<<std::endl;
}