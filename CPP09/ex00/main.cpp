/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:17:03 by lvodak            #+#    #+#             */
/*   Updated: 2024/10/01 17:07:36 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
		return std::cerr<<"Error : Wrong number of arguments"<<std::endl, 1;
	std::ifstream input(argv[1], std::ios::in);
	if (!input.is_open())
		return std::cerr<<"Error : Access File Denied"<<std::endl, 1;
	BitcoinExchange test;
	std::string line, value, date;
	while (getline(input, line))
	{
		if (date.empty() && !line.compare("date | value"))
			getline(input, line);
		date = line.substr(0, line.find_first_of("|"));
		value = line.substr(date.size() + (date.size() < line.size()));
		if (!(date.size()))
			break;
		test.compareInput(date, atof(value.c_str()));
	}
}