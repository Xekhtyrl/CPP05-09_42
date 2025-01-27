/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:39:55 by lvodak            #+#    #+#             */
/*   Updated: 2024/10/03 15:44:20 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <stdio.h>
#include <algorithm>


// Default constructor
BitcoinExchange::BitcoinExchange() {
	std::ifstream csv("./data.csv", std::ios::in);
	if (!csv.is_open()) {
		std::cerr<<"Error : Access Data File Denied. Program will be shut down!"<<std::endl;
		exit(1) ; }
	std::string line;
	std::string str;
	getline(csv, line);
	while(getline(csv, line))
	{
		str = line.substr(0, line.find_first_of(','));
		_data[str] = atof((line.substr(line.find_first_of(',') + 1)).c_str());
	}
	return; }

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
  *this = other;
  return;
}

// Copy assignment overload
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
  (void)rhs;
  return *this;
}

// Default destructor
BitcoinExchange::~BitcoinExchange() { return; }

void	BitcoinExchange::checkInput(std::string date, float value)
{
	int year = atoi((date.substr(0, date.find_first_of('-'))).c_str());
	int month = atoi((date.substr(date.find_first_of('-') + 1, 3)).c_str());
	int day = atoi((date.substr(date.find_last_of('-') + 1)).c_str());
	if (!isdigit(date[0]))
		throw std::runtime_error("No Valid date");
	if (value < 0 || value > 1000)
		throw std::runtime_error("Value out of scope");
	if (year < 2009 || (year == 2009 && month == 01 && day == 01))
		throw std::runtime_error("Year not in relevant scope");
	if (month < 1 || month > 12)
		throw std::runtime_error("No month of such value");
	switch (month)
	{
		case 1:
			if (day < 1 || day > 31)
				throw std::runtime_error("No such date for Jan");
			break ;
		case 2:
			if ((!(year % 4) && (day < 1 || day > 29)) || (year % 4 && (day < 1 || day > 28)))
				throw std::runtime_error("No such date for Fev");
			break ;
		case 3:
			if (day < 1 || day > 31)
				throw std::runtime_error("No such date for Mar");
			break;
		case 4:
			if (day < 1 || day > 30)
				throw std::runtime_error("No such date for Apr");
			break;
		case 5:
			if (day < 1 || day > 31)
				throw std::runtime_error("No such date for May");
			break;
		case 6:
			if (day < 1 || day > 30)
				throw std::runtime_error("No such date for Jun");
			break;
		case 7:
			if (day < 1 || day > 31)
				throw std::runtime_error("No such date for Jul");
			break;
		case 8:
			if (day < 1 || day > 31)
				throw std::runtime_error("No such date for Aug");
			break;
		case 9:
			if (day < 1 || day > 30)
				throw std::runtime_error("No such date for Sep");
			break;
		case 10:
			if (day < 1 || day > 31)
				throw std::runtime_error("No such date for Oct");
			break;
		case 11:
			if (day < 1 || day > 30)
				throw std::runtime_error("No such date for Nov");
			break;
		case 12:
			if (day < 1 || day > 31)
				throw std::runtime_error("No such date for Dec");
			break;
	}
}

void	BitcoinExchange::compareInput(std::string date, float value){
	long double new_val;
	try
	{
		checkInput(date, value);
		std::map<std::string, float>::iterator f;
		for (std::map<std::string, float>::iterator it1 = _data.begin(); it1->first <= date && it1 != _data.end(); it1++)
			f = it1;
		new_val = value * f->second;
		std::cout<<date<<" => "<<value<<" = "<< new_val<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: "<<e.what() << '\n';
	}
}