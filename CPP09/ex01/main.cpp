/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:38:50 by lvodak            #+#    #+#             */
/*   Updated: 2024/08/08 13:41:59 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int argc, char **argv) {
	if (argc != 2)
		return (std::cerr<<"This program handle one and only argument (i.e put in \" ...\")", 1);
	RPN::calculate(argv[1]);
}