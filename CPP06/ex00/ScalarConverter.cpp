/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:13:17 by lvodak            #+#    #+#             */
/*   Updated: 2024/09/21 18:28:48 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <stdio.h>
#include <limits.h>
#include <cfloat>
#include <iomanip>
#include <float.h>

// Default constructor
ScalarConverter::ScalarConverter() { return; }

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter &other) {
  *this = other;
  return;
}

// Copy assignment overload
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
  (void)rhs;
  return *this;
}

// Default destructor
ScalarConverter::~ScalarConverter() { return; }

void	ScalarConverter::toInt(std::string literal) {
	long long	in = atoll(literal.c_str());
	std::cout<<"int: ";
	if (!literal.compare("-inf") || !literal.compare("+inf") || !literal.compare("nan")
		|| (in == 0 && !(literal[0] == '0' || (literal[1] && literal[1] == '0'))))
		std::cout<<"impossiburu!!"<<std::endl;
	else if (in <= INT32_MAX && in >= INT32_MIN)
		std::cout<<(in)<<std::endl;
	else
		std::cout<<"out of limits"<<std::endl;
}
void	ScalarConverter::toChar(std::string literal) {
	long long	in = atoll(literal.c_str());
	std::cout<<"char: ";
	if (!literal.compare("-inf") || !literal.compare("+inf") || !literal.compare("nan")
		|| (in == 0 && !(literal[0] == '0' || (literal[1] && literal[1] == '0'))))
		std::cout<<"impossiburu!!"<<std::endl;
	else if (in < 2147483648 && in >= 0 && isprint((int)in))
		std::cout<<(char)((int)in)<<std::endl;
	else
		std::cout<<"non printable"<<std::endl;
}
void	ScalarConverter::toFloat(std::string literal) {
	long long	in = atoll(literal.c_str());
	std::cout<<"float: ";
	if (!literal.compare("-inf") || !literal.compare("+inf") || !literal.compare("nan"))
		std::cout<<literal+"f"<<std::endl;
	else if (!literal.compare("-inff") || !literal.compare("+inff") || !literal.compare("nanf"))
		std::cout<<literal<<std::endl;
	else if (in == 0 && !(literal[0] == '0' || (literal[1] && literal[1] == '0')))
		return (void)(std::cout<<"impossiburu!!"<<std::endl);
	else
	{
		if (in == atof(literal.c_str()))
			std::cout<< std::fixed << std::setprecision(1) << static_cast<float>(atof(literal.c_str()))<<"f"<<std::endl;
		else	
			std::cout<< std::fixed << static_cast<float>(atof(literal.c_str()))<<"f"<<std::endl;
	}
}
void	ScalarConverter::toDouble(std::string literal) {
	long long	in = atoll(literal.c_str());
	std::cout<<"double: ";
	if (!literal.compare("-inf") || !literal.compare("+inf") || !literal.compare("nan"))
		std::cout<<literal<<std::endl;
	else if (!literal.compare("-inff") || !literal.compare("+inff") || !literal.compare("nanf"))
		std::cout<<literal.substr(0, literal.size() - 1)<<std::endl;
	else if (in == 0 && !(literal[0] == '0' || (literal[1] && literal[1] == '0')))
		return (void)(std::cout<<"impossiburu!!"<<std::endl);
	else
		std::cout<< std::fixed << static_cast<double>(atof(literal.c_str()))<<std::endl;
}

void ScalarConverter::convert(std::string literal) {
	toChar(literal);
	toInt(literal);
	toFloat(literal);
	toDouble(literal);
}