/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 23:15:27 by lvodak            #+#    #+#             */
/*   Updated: 2024/07/31 23:46:35 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Identify.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base* p) {
	if (dynamic_cast<A*>(p) != nullptr)
		return (void)(std::cout<<"The type is A"<<std::endl);
	if (dynamic_cast<B*>(p) != nullptr)
		return (void)(std::cout<<"The type is B"<<std::endl);
	if (dynamic_cast<C*>(p) != nullptr)
		return (void)(std::cout<<"The type is C"<<std::endl);
}
void identify(Base& p) {
	try
	{
		p = dynamic_cast<A&>(p);
		return (void)(std::cout<<"The type is A"<<std::endl);
	}
	catch (...)
	{
		try{
			p = dynamic_cast<B&>(p);
			return (void)(std::cout<<"The type is B"<<std::endl);
		}
		catch(...)
		{
			try{
				p = dynamic_cast<C&>(p);
				return (void)(std::cout<<"The type is C"<<std::endl);
			}
			catch(...)
			{
				std::cout<<"no match"<<std::endl;
			}
		}
	}
}