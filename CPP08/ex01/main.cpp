/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:38:18 by lvodak            #+#    #+#             */
/*   Updated: 2024/08/05 19:19:46 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	srand(time(NULL));
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	// int testSize = 0;
	// int testSize = 1;
	int testSize = 10000;
	std::vector<int> lg;
	for (int i = 0; i < testSize; i++)
	{
		lg.push_back(rand());
		std::cout<<i<<" = "<<lg.at(i)<<std::endl;
	}
	Span big(testSize);
	std::cout<<"span created"<<std::endl;
	try
	{
		big.addNumber(lg);
		std::cout<<"number added"<<std::endl;
		std::cout << big.shortestSpan() << std::endl;
		std::cout << big.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}