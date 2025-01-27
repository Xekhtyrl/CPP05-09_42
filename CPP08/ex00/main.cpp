/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 19:05:15 by lvodak            #+#    #+#             */
/*   Updated: 2024/08/02 19:34:19 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main(){
	std::vector<int> test;
	for (int i = 0; i < 10; i++)
		test.push_back(i * 2);
	//  std::vector<int> test{10, 20, 30, 40};
	try
	{
		std::cout<<::easyfind(test, 6) - test.begin()<<std::endl;
		std::cout<<::easyfind(test, 2) - test.begin()<<std::endl;
		std::cout<<::easyfind(test, 5) - test.begin()<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}