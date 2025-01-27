/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:12:13 by lvodak            #+#    #+#             */
/*   Updated: 2024/08/08 18:20:58 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stdio.h>

// Default constructor
RPN::RPN() { return; }

// Copy constructor
RPN::RPN(const RPN &other) {
  *this = other;
  return;
}

// Copy assignment overload
RPN &RPN::operator=(const RPN &rhs) {
  (void)rhs;
  return *this;
}

// Default destructor
RPN::~RPN() { return; }

static int	isOperator(char c)
{
	char set[5]  = {'+', '-', '/', '*', 0};
	for (int i = 0; i < 5; i++)
		if (c == set[i]++)
			return 1;
	return 0;
}
void RPN::calculate(char *input) {
	int result;
	std::stack<int>stack;
	for (size_t i = 0; i < strlen(input); i++)
	{
		if (isdigit(input[i]))
			break;
		if (i == strlen(input) - 1)
			return ((void)(std::cerr<<"Error: no digit found"<<std::endl));
	}
	for (size_t i = 0; i < strlen(input); i++)
	{
		if (isdigit(input[i]) || (input[i] == '-' && isdigit(input[i + 1])))
		{
			if (atoi(&input[i]) < 10 && atoi(&input[i]) >= 0)
				stack.push(atoi(&input[i]));
			else
				return ((void)(std::cerr<<"Error: "<<atoi(&input[i])<<" is not a valid number (> 0 & < 10)!"<<std::endl));
		}
		else if(isOperator(input[i]) && stack.size() > 1) {
			result = stack.top();
			stack.pop();
			switch (input[i])
			{
			case 43:
				result = (int)(stack.top()) + result;
				break ;
			case 45:
				result = (int)stack.top() - result;
				break ;
			case 47:
				result = (int)stack.top() / result;
				break ;
			case 42:
				result = (int)stack.top() * result;
				break ;
			default:
				break;
			}
			stack.pop();
			stack.push(result);
		}
		else if(isOperator(input[i]) && stack.size() <= 1)
			return ((void)(std::cerr<<"Error: not enough digit before operator"<<std::endl));
		else if(!isspace(input[i]))
			return ((void)(std::cerr<<"Error: "<<input[i]<<" is not a valid character!"<<std::endl));
	}
	if (strlen(input))
		std::cout<<stack.top()<<std::endl;
}