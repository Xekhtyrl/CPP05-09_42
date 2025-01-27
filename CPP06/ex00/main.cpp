/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:42:19 by lvodak            #+#    #+#             */
/*   Updated: 2024/09/21 18:32:39 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
		return (std::cout<<"No arguments inserted"<<std::endl, 1);
	ScalarConverter::convert((std::string)argv[1]);
}